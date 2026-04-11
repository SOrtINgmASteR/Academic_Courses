// Boundary Fill Algorithm
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

int window_width = 640, window_height = 640;
unsigned char fill_color[3]   = {102,128,153};
unsigned char border_color[3] = {0,0,0};
stack<pair<int, int>> pixels;

void get_pixel(int x, int y, unsigned char color_x_y[3]){
    glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, color_x_y);
}

void set_pixel(int x, int y, unsigned char fill_color[3]){
    glColor3ubv(fill_color);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    Sleep(1500);
    cout << "Setting pixel at: (" << x << ", " << y << ")" << endl;
    glEnd();
    glFlush();
    glFinish();
}

bool same_color(const unsigned char a[3], const unsigned char b[3]){
    return (a[0] == b[0] && a[1] == b[1] && a[2] == b[2]);
}

void boundary_fill(int x, int y){
    unsigned char color[3];
    get_pixel(x, y, color);
    pixels.push(make_pair(x, y));
    while(pixels.size() > 0){
        pair<int, int> pixel = pixels.top();
        pixels.pop();
        int x = pixel.first;
        int y = pixel.second;

        if (x < 0 || x >= window_width || y < 0 || y >= window_height) continue;
        get_pixel(x, y, color);
        cout << "Color at (" << x << ", " << y << "): (" << (int)color[0] << ", " << (int)color[1] << ", " << (int)color[2] << ")" << endl;
        if((!same_color(color, border_color)) && (!same_color(color, fill_color))){
            set_pixel(x, y, fill_color);
            pixels.push(make_pair(x + 1, y));
            pixels.push(make_pair(x - 1, y));
            pixels.push(make_pair(x, y + 1));
            pixels.push(make_pair(x, y - 1));
        }
    }
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        int click_x = x;
        int click_y = window_height - y;
        boundary_fill(click_x, click_y);
        cout << "Clicked at: (" << click_x << ", " << click_y << ")" << endl;
    }
}

void draw_polygon(int x1, int y1, int x2, int y2){
    glColor3ubv(border_color);
    glLineWidth(3.0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(x1, y1);
        glVertex2i(x2, y1);
        glVertex2i(x2, y2);
        glVertex2i(x1, y2);
    glEnd();
    glFlush();
}

void init(void){
    glClearColor(0, 0.7, 0.5, 0.0);
    glDisable(GL_DITHER);
    glColor3ubv(border_color);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, window_width, 0.0, window_height);
}

void display(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    draw_polygon(150, 250, 200, 300);
    glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(window_width, window_height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Boundary Fill Algorithm");
    glutDisplayFunc(display);
    init();
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
