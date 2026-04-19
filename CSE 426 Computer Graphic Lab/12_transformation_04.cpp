// Transformations (Scale, Rotate, Translate) + Undo + Reset (Deque History)
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <deque>
#include <array>
using namespace std;

const GLfloat tri[3][2] = {
    {0.1f, 0.4f},
    {0.7f, 0.4f},
    {0.4f, 0.8f}
};

const int MAX_HISTORY = 3;

deque<array<float,16>> history;
int current = -1; // index in deque

void drawTriangle(){
    glBegin(GL_POLYGON);
    glVertex2f(tri[0][0], tri[0][1]);
    glVertex2f(tri[1][0], tri[1][1]);
    glVertex2f(tri[2][0], tri[2][1]);
    glEnd();
}

void reset(){
    history.clear();
    current = -1;
}

void pushCurrentMatrix(){
    array<float,16> m;
    glGetFloatv(GL_MODELVIEW_MATRIX, m.data());

    // If we undid and then applied a new transform, drop "future" history
    while((int)history.size() - 1 > current){
        history.pop_back();
    }

    history.push_back(m);

    // keep only last MAX_HISTORY
    if((int)history.size() > MAX_HISTORY){
        history.pop_front();
        // shift current index left because front was removed
        current--;
    }

    current = (int)history.size() - 1;
}

void applyHistoryMatrix(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    if(current >= 0 && current < (int)history.size()){
        glMultMatrixf(history[current].data());
    }
}

void applyRotation(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.1f, 0.4f, 0.0f);
    glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
    glTranslatef(-0.1f, -0.4f, 0.0f);
    pushCurrentMatrix();
}

void applyScaling(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.1f, 0.4f, 0.0f);
    glScalef(1.5f, 1.5f, 1.0f);
    glTranslatef(-0.1f, -0.4f, 0.0f);
    pushCurrentMatrix();
}

void applyTranslation(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.2f, 0.1f, 0.0f);
    pushCurrentMatrix();
}

void undo(){
    if(current >= 0) current--;
}

void option_menu(GLint option){
    switch(option){
        case 1: applyRotation(); break;
        case 2: applyScaling(); break;
        case 3: applyTranslation(); break;
        case 4: undo(); break;
        case 5: reset(); break;
        default: break;
    }
    glutPostRedisplay();
}

void init(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    applyHistoryMatrix();
    glColor3f(1.0f, 0.2f, 0.0f);
    drawTriangle();

    glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Transformations + Undo (Deque)");

    init();
    glutDisplayFunc(display);

    glutCreateMenu(option_menu);
    glutAddMenuEntry("Rotate", 1);
    glutAddMenuEntry("Scale", 2);
    glutAddMenuEntry("Translate", 3);
    glutAddMenuEntry("Undo", 4);
    glutAddMenuEntry("Reset", 5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}