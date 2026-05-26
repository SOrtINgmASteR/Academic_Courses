#include <iostream>
#include <cmath>
#include <ctime>
#include <GL/glut.h>
using namespace std;

void plot_circle_pixel(int x, int y, int xc, int yc){
    glBegin(GL_POINTS);
    glVertex2i(x + xc, y + yc);
    glEnd();
}

void mid_point_circle(int xc, int yc, int r){
    int x = 0;
    int y = r;

    float decision = 5.0f / 4.0f - (float)r;

    while (y >= x) {
        plot_circle_pixel( x,  y, xc, yc);
        plot_circle_pixel( x, -y, xc, yc);
        plot_circle_pixel(-x,  y, xc, yc);
        plot_circle_pixel(-x, -y, xc, yc);
        plot_circle_pixel( y,  x, xc, yc);
        plot_circle_pixel(-y,  x, xc, yc);
        plot_circle_pixel( y, -x, xc, yc);
        plot_circle_pixel(-y, -x, xc, yc);

        if (decision < 0) {
            x++;
            decision += 2.0f * x + 3.0f;
        } else {
            y--;
            x++;
            decision += 2.0f * (x - y) + 5.0f;
        }
    }
}

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


int clockCenterX = 320;
int clockCenterY = 240;
int clockRadius  = 150;

float degToRad(float deg) {
    return (3.14159265f / 180.0f) * deg;
}


void draw_hand(int cx, int cy, float angleDeg, float length) {
    float rad = degToRad(angleDeg);

    int x0 = cx;
    int y0 = cy;

    int x1 = cx + (int)(length * sin(rad));
    int y1 = cy + (int)(length * cos(rad));
    bresenham_line(x0, y0, x1, y1);
}

void draw_filled_circle(int cx, int cy, int r) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f((float)cx, (float)cy);
    for (int a = 0; a <= 360; a++) {
        float rad = degToRad((float)a);
        float x = cx + r * cos(rad);
        float y = cy + r * sin(rad);
        glVertex2f(x, y);
    }
    glEnd();
}

void draw_ticks() {
    for (int i = 0; i < 60; i++) {
        float angle = (float)i * 6.0f; 

        float rad = degToRad(angle);

        int xOuter = clockCenterX + (int)((clockRadius - 5) * sin(rad));
        int yOuter = clockCenterY + (int)((clockRadius - 5) * cos(rad));

        int tickLen = (i % 5 == 0) ? 15 : 8;
        int xInner = clockCenterX + (int)((clockRadius - 5 - tickLen) * sin(rad));
        int yInner = clockCenterY + (int)((clockRadius - 5 - tickLen) * cos(rad));

        glPointSize((i % 5 == 0) ? 3.0f : 2.0f);

        bresenham_line(xInner, yInner, xOuter, yOuter);
    }
}

void get_time_angles(float &hourAngle, float &minuteAngle, float &secondAngle) {
    std::time_t t = std::time(nullptr);
    std::tm *now = std::localtime(&t);

    int hr = now->tm_hour % 12;
    int mn = now->tm_min;
    int sc = now->tm_sec;

    secondAngle = sc * 6.0f;

    minuteAngle = mn * 6.0f + (sc / 60.0f) * 6.0f;

    hourAngle = hr * 30.0f + (mn / 60.0f) * 30.0f;
}

void draw_clock() {
    glColor3f(0.95f, 0.95f, 0.92f); // light warm
    draw_filled_circle(clockCenterX, clockCenterY, clockRadius - 1);

    glColor3f(0.10f, 0.10f, 0.10f);
    glPointSize(2.5f);
    mid_point_circle(clockCenterX, clockCenterY, clockRadius);

    glColor3f(0.15f, 0.15f, 0.15f);
    draw_ticks();

    glColor3f(0.10f, 0.10f, 0.10f);
    glPointSize(3.0f);
    mid_point_circle(clockCenterX, clockCenterY, 6);

    float hourAngle, minuteAngle, secondAngle;
    get_time_angles(hourAngle, minuteAngle, secondAngle);

    glColor3f(0.10f, 0.10f, 0.10f);
    glPointSize(4.0f);
    draw_hand(clockCenterX, clockCenterY, hourAngle, clockRadius * 0.50f);

    glColor3f(0.05f, 0.05f, 0.05f);
    glPointSize(3.0f);
    draw_hand(clockCenterX, clockCenterY, minuteAngle, clockRadius * 0.72f);

    glColor3f(0.85f, 0.12f, 0.12f);
    glPointSize(2.0f);
    draw_hand(clockCenterX, clockCenterY, secondAngle, clockRadius * 0.88f);

    glColor3f(0.85f, 0.12f, 0.12f);
    draw_filled_circle(clockCenterX, clockCenterY, 4);
}

void timerFunc(int value) {
    glutPostRedisplay();
    glutTimerFunc(33, timerFunc, 0);
}

void myInit(void){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void myDisplay(void){
    glClear(GL_COLOR_BUFFER_BIT);
    draw_clock();

    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Real-Time Analog Clock (Bresenham + Midpoint Circle)");

    myInit();
    glutDisplayFunc(myDisplay);
    glutTimerFunc(0, timerFunc, 0);

    glutMainLoop();
    return 0;
}