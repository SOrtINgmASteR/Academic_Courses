// Transformations (Scale, Rotate, Translate)
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <cmath>
using namespace std;

const GLfloat tri[3][2] = {
    {0.1f, 0.4f},
    {0.7f, 0.4f},
    {0.4f, 0.8f}
};

int mode = 0;

void drawPolygon(const GLfloat v[3][2]){
    glBegin(GL_POLYGON);
    for(int i = 0; i < 3; i++) glVertex2f(v[i][0], v[i][1]);
    glEnd();
}

void rotate_origin(float angleDeg){
    GLfloat v[3][2];
    float angle = angleDeg * 3.1415926f / 180.0f;

    // rotate around center (0.4,0.5333)
    float cx = (tri[0][0] + tri[1][0] + tri[2][0])/3.0f;
    float cy = (tri[0][1] + tri[1][1] + tri[2][1])/3.0f;

    for(int i = 0; i < 3; i++){
        float x = tri[i][0]-cx;
        float y = tri[i][1]-cy;
        v[i][0] = x*cos(angle) - y*sin(angle) + cx;
        v[i][1] = x*sin(angle) + y*cos(angle) + cy;
    }
    drawPolygon(v);
}

void scale_center(float sx, float sy){
    GLfloat v[3][2];
    float cx = (tri[0][0] + tri[1][0] + tri[2][0])/3.0f;
    float cy = (tri[0][1] + tri[1][1] + tri[2][1])/3.0f;

    for(int i = 0; i < 3; i++){
        float x = tri[i][0]-cx;
        float y = tri[i][1]-cy;
        v[i][0] = x*sx + cx;
        v[i][1] = y*sy + cy;
    }
    drawPolygon(v);
}

void translate_center(float tx, float ty){
    GLfloat v[3][2];
    for(int i = 0; i < 3; i++){
        v[i][0] = tri[i][0] + tx;
        v[i][1] = tri[i][1] + ty;
    }
    drawPolygon(v);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    switch(mode){
        case 1: glColor3f(0,1,0); rotate_origin(45); break;
        case 2: glColor3f(1,0,0); scale_center(1.5f,1.5f); break;
        case 3: glColor3f(0,0,1); translate_center(0.2f,0.1f); break;
        default: glColor3f(1,0.2f,0); drawPolygon(tri); break;
    }
    glFlush();
}

void option_menu(GLint option){
    mode = option;
    glutPostRedisplay();
}

void init(){
    glClearColor(1,1,1,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1, 0, 1);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Transformations");

    init();
    glutDisplayFunc(display);

    glutCreateMenu(option_menu);
    glutAddMenuEntry("Rotate", 1);
    glutAddMenuEntry("Scale", 2);
    glutAddMenuEntry("Translate", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}