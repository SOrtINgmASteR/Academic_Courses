#include <GL/freeglut.h>

int x0 = 2, y0 = 2, x1 = 50, y1 = 36;

void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
        glVertex2i(x, y);
    glEnd();
}

void bresenhamLine() {
    int dx = x1 - x0;
    int dy = y1 - y0;

    int p = 2 * dy - dx;
    int x = x0;
    int y = y0;

    drawPixel(x, y);

    while (x < x1) {
        x++;
        if (p < 0) {
            p += 2 * dy;
        } else {
            y++;
            p += 2 * dy - 2 * dx;
        }
        drawPixel(x, y);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1);
    bresenhamLine();
    glFlush();
}

void init() {
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 50, 0, 50);
    glPointSize(3.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham Line Drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
