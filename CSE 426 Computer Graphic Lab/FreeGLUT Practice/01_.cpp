// Points
#include <GL/freeglut.h>
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    //GL_POINTS means that each vertex specified will be drawn as a single point.
    glBegin(GL_POINTS);             
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0,1);
        glVertex2f(0,-1);
        glVertex2f(-1,0);
        glVertex2f(-0.5,0.5);
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
