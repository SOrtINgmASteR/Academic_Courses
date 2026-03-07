#include <iostream>
#include <GL/glut.h>
using namespace std;
int pntx1, pnty1, r;
void plot(int x, int y, int pntX1, int pntY1)
{
    glBegin(GL_POINTS);
    glVertex2i(x + pntX1, y + pntY1);
    glEnd();
}
void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(5.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void midPointCircleAlgo(int pntX1, int pntY1, int r)
{
    int x = 0;
    int y = r;
    float decision = 5 / 4 - r;
    plot(x, y, pntX1, pntY1);
    while (y > x)
    {
        if (decision < 0)
        {
            x++;
            decision += 2 * x +3;
        }
        else
        {
            y--;
            x++;
            decision += 2 * (x - y) + 5;
        }
        plot(x, y, pntX1, pntY1);
        plot(x, -y, pntX1, pntY1);
        plot(-x, y, pntX1, pntY1);
        plot(-x, -y, pntX1, pntY1);
        plot(y, x, pntX1, pntY1);
        plot(-y, x, pntX1, pntY1);
        plot(y, -x, pntX1, pntY1);
        plot(-y, -x, pntX1, pntY1);
    }
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(5.0);
    midPointCircleAlgo(pntx1, pnty1, r);
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Line Drawing Alogrithms");
    printf("Enter the center of the Circle : ");
    scanf("%d %d", &pntx1, &pnty1);
    printf("Enter the radius of the Circle : ");
    scanf("%d", &r);
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}