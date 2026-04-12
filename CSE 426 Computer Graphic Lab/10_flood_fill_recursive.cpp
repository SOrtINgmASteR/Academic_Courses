// Flood Fill Algorithm
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std; 

int window_width = 600, window_height = 500;  
float bg_color[3] = { 0.0, 0.9, 0.7};  
float initial_color[3] = {1.0, 0.0, 0.0 };  
float fill_color[3] = {1, 0.5, 0.7}; 

void setPixel(int x, int y, float color[3])  {
    glBegin(GL_POINTS);  
    glColor3fv(color);  
    glVertex2i(x, y);  
    glEnd();  
    glFlush(); 
} 

void getPixel(int x, int y, float color[3]) {  
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, color); 
}

void flood_fill(int x, int y, float old_color[3], float new_color[3])  { 
    float color[3];  
    getPixel(x, y, color);  
    if (color[0] == old_color[0] && (color[1]) == old_color[1] && (color[2]) ==  old_color[2]) { 
      setPixel(x, y, new_color);  
          flood_fill(x + 1, y, old_color, new_color);  
          flood_fill(x - 1, y, old_color, new_color);  
          flood_fill(x, y + 1, old_color, new_color);  
          flood_fill(x, y - 1, old_color, new_color);  
    }  
}

void mouse(int btn, int state, int x, int y)  {  
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        int xi = x;  
        int yi = (window_height - y);  
        flood_fill(xi, yi, initial_color, fill_color);  
    } 
} 

void drawPolygon(int x1, int y1, int x2, int y2) {  
    glColor3f(1.0, 0.0, 0.0);  
    glBegin(GL_POLYGON);  
    glVertex2i(x1, y1);  
    glVertex2i(x1, y2);  
    glVertex2i(x2, y2);  
    glVertex2i(x2, y1);  
    glEnd();  
    glFlush(); 
}  

void display() {  
    glClearColor(0.2, 0.4, 0.0, 0.6);  
    glClear(GL_COLOR_BUFFER_BIT);  
    drawPolygon(150, 250, 200, 300);  
    glFlush(); 
}  

void init() {  
    glViewport(0, 0, window_width, window_height);  
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity();  
    gluOrtho2D(0.0, (GLdouble)window_width, 0.0, (GLdouble)window_height);  
    glMatrixMode(GL_MODELVIEW);  
}  

int main(int argc, char** argv)  {  
    glutInit(&argc, argv);  
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
    glutInitWindowSize(window_width, window_height);  
    glutCreateWindow("Flood-Fill");  
    glutDisplayFunc(display);  
    init();  
    glutMouseFunc(mouse);  
    glutMainLoop();  
    return 0;  
  } 