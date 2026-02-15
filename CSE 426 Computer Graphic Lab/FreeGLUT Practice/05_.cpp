// Polygon
#include <GL/freeglut.h>
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    // GL_POLYGON means that the vertices specified will be connected to form a filled polygon.
    glBegin(GL_POLYGON);
        glVertex2f(0.75f, 0.95f);
        glVertex2f(-0.25f, 0.95f);
        glVertex2f(-0.85f, -0.55f);
        glVertex2f(-0.25f, -0.35f);
        glVertex2f(0.75f, -0.55f);
    glEnd();
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Window");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}