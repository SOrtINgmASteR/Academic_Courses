#include <GL/freeglut.h>
#include <GL/glut.h>
#include <bits/stdc++.h>

void init(void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}


int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("CSE 426 Computer Graphics Lab");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
