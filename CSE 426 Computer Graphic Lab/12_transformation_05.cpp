// Transformations with Circular Undo/Redo History (size N)
#include <GL/freeglut.h>
#include <cmath>
#include <iostream>
using namespace std;

const int N = 4; 

typedef struct {
    float rotation_angle;
    float scale_factor;
    float translate_x;
    float translate_y;
} transform_state;


const GLfloat tri[3][2] = {
    {0.1f, 0.4f},
    {0.7f, 0.4f},
    {0.4f, 0.8f}
};

transform_state history[N];
int head = -1;     // newest index
int sizeH = 0;     // number of valid states
int current = -1;  // current index

int oldestIndex(){
    return (head - (sizeH - 1) + N) % N;
}

// truncate redo chain when pushing new state after undo
void truncateRedo(){
    if(sizeH == 0 || current == head) return;

    int old = oldestIndex();
    int newSize = (current >= old) ? (current - old + 1) : ((current + N) - old + 1);
    head = current;
    sizeH = newSize;
}

void push_state(transform_state s){
    if(sizeH == 0){
        head = 0;
        sizeH = 1;
        current = 0;
        history[0] = s;
        return;
    }
    truncateRedo();

    head = (head + 1) % N;
    history[head] = s;
    if(sizeH < N) sizeH++;
    current = head;
}

bool undo_state(transform_state &out){
    if(sizeH == 0) return false;
    if(current == oldestIndex()) return false;
    current = (current - 1 + N) % N;
    out = history[current];
    return true;
}

bool redo_state(transform_state &out){
    if(sizeH == 0) return false;
    if(current == head) return false;
    current = (current + 1) % N;
    out = history[current];
    return true;
}

bool get_current(transform_state &out){
    if(sizeH == 0) return false;
    out = history[current];
    return true;
}

void reset_history(){
    head = -1;
    current = -1;
    sizeH = 0;
}

void print_history(){
    cout << "History: ";
    for(int i = 0; i < N; i++){
        cout << "[" << history[i].translate_x << "," << history[i].translate_y << "," << history[i].scale_factor << "," << history[i].rotation_angle << "] ";
    }
    cout << "\n";
}

transform_state state = {0.0f, 1.0f, 0.0f, 0.0f};

void drawTriangle(){
    glBegin(GL_POLYGON);
    glVertex2f(tri[0][0], tri[0][1]);
    glVertex2f(tri[1][0], tri[1][1]);
    glVertex2f(tri[2][0], tri[2][1]);
    glEnd();
}

void applyState(const transform_state &s){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(s.translate_x, s.translate_y, 0.0f);
    glRotatef(s.rotation_angle, 0.0f, 0.0f, 1.0f);
    glScalef(s.scale_factor, s.scale_factor, 1.0f);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    transform_state cur;
    if(get_current(cur)) applyState(cur);
    else applyState(state); // fallback

    glColor3f(1.0f, 0.2f, 0.0f);
    drawTriangle();

    glFlush();
}

void option_menu(GLint option){
    switch(option){
        case 1: // Rotate 15 degrees
            state.rotation_angle += 15.0f;
            push_state(state);
            break;
        case 2: // Scale up by 0.2
            state.scale_factor += 0.2f;
            push_state(state);
            break;
        case 3: // Translate by (0.1, 0.1)
            state.translate_x += 0.1f;
            state.translate_y += 0.1f;
            push_state(state);
            break;
        case 4: { // Undo
            if(undo_state(state)){}
            break;
        }
        case 5: { // Redo
            if(redo_state(state)){}
            break;
        }
        case 6: { // Reset
            state = {0.0f, 1.0f, 0.0f, 0.0f};
            reset_history();
            push_state(state);
            break;
        }
        default: break;
    }
    print_history();
    glutPostRedisplay();
}

void init(){
    glClearColor(1,1,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1, 0, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // initial state
    push_state(state);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Transformations with Undo/Redo (Circular History)");

    init();
    glutDisplayFunc(display);

    glutCreateMenu(option_menu);
    glutAddMenuEntry("Rotate (+15°)", 1);
    glutAddMenuEntry("Scale (+0.2)", 2);
    glutAddMenuEntry("Translate (+0.1,+0.1)", 3);
    glutAddMenuEntry("Undo", 4);
    glutAddMenuEntry("Redo", 5);
    glutAddMenuEntry("Reset", 6);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}