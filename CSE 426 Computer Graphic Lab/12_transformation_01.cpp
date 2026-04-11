// Transformations (Scale, Rotate, Translate) - Modular
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

// Triangle vertices
const GLfloat tri[3][2] = {
    {0.1f, 0.4f},
    {0.7f, 0.4f},
    {0.4f, 0.8f}
};

void drawTriangle(){
    glBegin(GL_POLYGON);
    glVertex2f(tri[0][0], tri[0][1]);
    glVertex2f(tri[1][0], tri[1][1]);
    glVertex2f(tri[2][0], tri[2][1]);
    glEnd();
    glFlush();
}

void applyRotation(){
    // glLoadIdentity();
    glTranslatef(0.1f, 0.4f, 0.0f);
    glRotatef(45.0f, 0.0f, 0.0f, 1.0f);
    glTranslatef(-0.1f, -0.4f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    drawTriangle();
}

void applyScaling(){
    // glLoadIdentity();
    glTranslatef(0.1f, 0.4f, 0.0f);
    glScalef(1.5f, 1.5f, 1.0f);
    glTranslatef(-0.1f, -0.4f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    drawTriangle();
}

void applyTranslation(){
    // glLoadIdentity();
    glTranslatef(0.2f, 0.1f, 0.0f); 
    glColor3f(0.0f, 0.0f, 1.0f);
    drawTriangle();
}

void option_menu(GLint option){
    glClear(GL_COLOR_BUFFER_BIT);
    switch(option){
        case 1: applyRotation(); break;
        case 2: applyScaling(); break;
        case 3: applyTranslation(); break;
        default: break;
    }
    glFlush();
    glutPostRedisplay();
}

void init(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0); // normalized coords
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(8.0f, 0.2f, 0.0f);
    drawTriangle();
    glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Transformations");

    init();
    glutDisplayFunc(display);

    glutCreateMenu(option_menu);
    glutAddMenuEntry("Rotate", 1);
    glutAddMenuEntry("Scale", 2);
    glutAddMenuEntry("Translate", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}