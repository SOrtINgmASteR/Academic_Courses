// Line Loop
#include <GL/freeglut.h>
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    /* GL_LINE_LOOP means that each vertex specified will be connected to the next
    and the last vertex will be connected to the first. */
    glBegin(GL_LINE_LOOP);             
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
