#include <iostream>
#include <cmath>
#include <GL/glut.h>
using namespace std;

int xf = 0, yf = 0, xs = 0, ys = 0;

void draw_line_pixel(int x, int y){
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void bresenham_line(int xf, int yf, int xs, int ys){
    int dx, dy, p, x, y, inc_x = 1, inc_y = 1;
    dx = xs - xf;
    dy = ys - yf;
    if(dx < 0) dx *= -1;
    if(dy < 0) dy *= -1;

    if(xs < xf) inc_x = -1;
    if(ys < yf) inc_y = -1;

    if(dx > dy){
        p = 2 * dy - dx;
        x = xf;
        y = yf;
        draw_line_pixel(x, y);
        for(int i = 0; i < dx; i++){
            if(p < 0){
                p += 2 * dy;
                x += inc_x;
            }
            else{
                p += 2 * dy - 2 * dx;
                x += inc_x;
                y += inc_y;
            }
            draw_line_pixel(x, y);
        }
    }
    else{
        p = 2 * dx - dy;
        x = xf;
        y = yf;
        draw_line_pixel(x, y);
        for(int i = 0; i < dy; i++){
            if(p < 0){
                p += 2 * dx;
                y += inc_y;
            }
            else{
                p += 2 * dx - 2 * dy;
                x += inc_x;
                y += inc_y;
            }
            draw_line_pixel(x, y);
        }
    }
}

float degToRad(float deg) {
    return (3.14159265f / 180.0f) * deg;
}

int cx = 320;         
int cy = 240;         
float L = 120.0f;     
float angle = 0.0f;  

void draw_angled_line(int x0, int y0, float angleDeg, float length) {
    float rad = degToRad(angleDeg);
    int x1 = x0 + (int)(length * cos(rad));
    int y1 = y0 - (int)(length * sin(rad));
    bresenham_line(x0, y0, x1, y1);
}

void myInit(void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(3.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


void update_line() {
    Sleep(50);
    angle += 1.0f;
    if (angle >= 360.0f) angle -= 360.0f;
    glutPostRedisplay();
}

void myDisplay(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(3.0);
    draw_angled_line(cx, cy,   angle, L);
    glFlush();
}


int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Lines in Different Angles (Bresenham)");

    glutDisplayFunc(myDisplay);
    myInit();

    glutIdleFunc(update_line);
    glutMainLoop();
}