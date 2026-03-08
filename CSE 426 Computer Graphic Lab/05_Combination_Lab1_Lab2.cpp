#include <iostream>
#include <GL/glut.h>
using namespace std;

// Circle Variables
int xc, yc, r;
void plot_circle_pixel(int x, int y, int xc, int yc){
    glBegin(GL_POINTS);
    glVertex2i(x + xc, y + yc);
    glEnd();
}
void mid_point_circle(int xc, int yc, int r){
    int x = 0;
    int y = r;
    float decision = 5 / 4 - r;
    plot_circle_pixel(x, y, xc, yc);
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
        plot_circle_pixel(x, y, xc, yc);
        plot_circle_pixel(x, -y, xc, yc);
        plot_circle_pixel(-x, y, xc, yc);
        plot_circle_pixel(-x, -y, xc, yc);
        plot_circle_pixel(y, x, xc, yc);
        plot_circle_pixel(-y, x, xc, yc);
        plot_circle_pixel(y, -x, xc, yc);
        plot_circle_pixel(-y, -x, xc, yc);
    }
}


// Line Variables
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
        x= xf;
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

void myInit(void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(5.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void myDisplay(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(3.0);
    mid_point_circle(100, 100, 50);
    bresenham_line(200, 200, 300, 300);
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("CSE 426 - Lab 1 & Lab 2");

    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
}