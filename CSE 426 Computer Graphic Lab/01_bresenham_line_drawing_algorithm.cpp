#include <GL/freeglut.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;
int xf = 0, yf = 0, xs = 0, ys = 0;

void init(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void draw_pixel(int x, int y){
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
        draw_pixel(x, y);
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
            draw_pixel(x, y);
        }
    }
    else{
        p = 2 * dx - dy;
        x= xf;
        y = yf;
        draw_pixel(x, y);
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
            draw_pixel(x, y);
        }
    }
}

void display(){
    bresenham_line(xf, yf, xs, ys);
    glFlush();
}


int main(int argc, char** argv) {
    cout << "Enter the coordinates of the first point (x1, y1): ";
    cin >> xf >> yf;
    cout << "Enter the coordinates of the second point (x2, y2): ";
    cin >> xs >> ys;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham's Line Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}