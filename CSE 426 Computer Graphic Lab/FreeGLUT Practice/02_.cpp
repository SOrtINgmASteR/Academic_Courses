// Lines
#include <GL/freeglut.h>
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    //GL_LINES means that each pair of vertices specified will be drawn as a line.
    glBegin(GL_LINES);             
        glVertex2f(0,1);
        glVertex2f(-0.5,0.5);
        glVertex2f(0,-1);
        glVertex2f(-1,0);
        glVertex2f(-0.75f,-2.5f);
        glVertex2f(-0.5f,-0.35f);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Window");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
