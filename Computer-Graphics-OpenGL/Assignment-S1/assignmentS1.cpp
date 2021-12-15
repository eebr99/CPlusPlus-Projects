//Eric Blanco
#include <math.h>
#include <Windows.h>
#include <GL\glew.h> //different includes necessary for my machine
#include <GL\freeglut.h>
#include <iostream>
#include <stdlib.h>

void exit(int);
//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
void myInit() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.5, 1.5, -2.5, 2.5, -3.5, 3.5);
}
//<<<<<<<<<<<<<<<<<<<<<<<< Shapes >>>>>>>>>>>>>>>>>
void point() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.15f, 0.10f);
    glVertex3f(0.0, 0.0, 0.0);
    glEnd();
    glFlush();
    glutPostRedisplay();
}

void line() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5f, 0.0f, 0.75f);
    glVertex3f(-1.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, -1.0, 0.0);
    glEnd();
    glFlush();
    glutPostRedisplay();
}

void triangle() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0, -1.0, 0.0);
    glVertex3f(1.0, -1.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    glEnd();
    glFlush();
    glutPostRedisplay();
}

void square() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(-1.0, 1.0, 0.0); // top left
    glVertex3f(1.0, 1.0, 0.0); // top right 
    glVertex3f(1.0, -1.0, 0.0); // bottom right
    glVertex3f(-1.0, -1.0, 0.0); // bottom left
    glEnd();
    glFlush();
    glutPostRedisplay();
}

void hexagon() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.5f);
    glVertex3f(-0.75, 2.25, 0.0); // top left // points so that edges = 1.5 
    glVertex3f(0.75, 2.25, 0.0); // top right 
    glVertex3f(1.40, 0.0, 0.0); // center right
    glVertex3f(0.75, -2.25, 0.0); // bottom right
    glVertex3f(-0.75, -2.25, 0.0); // bottom left
    glVertex3f(-1.40, 0.0, 0.0); // center left
    glEnd();
    glFlush();
    glutPostRedisplay();
}

void circle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(0.25f, 0.85f, 1.0f);

    int i;
    int triangleAmount = 40; //# of gons

    GLfloat twicePi = 2.0f * 3.1415926f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(x, y, z); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex3f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount)),
            z
        );
    }
    glEnd();
    glFlush();
    glutPostRedisplay();
}

void cube() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_POLYGON);
    //front side:
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0, 1.0, -1.0); //top left
    glVertex3f(1.0, 1.0, -1.0);  //top right
    glVertex3f(1.0, -1.0, -1.0); //bottom right
    glVertex3f(-1.0, -1.0, -1.0); //bottom left
    //back side:
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    //left side:
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0); 
    //right side:
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, 1.0); 
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);
    //top side:
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(1.0, 1.0, -1.0);
    //bottom side:
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, -1.0);

    glEnd();
    glFlush();
    glutPostRedisplay();
}
//<<<<<<<<<<<<<<<<<<<<<<<< myKeyboard >>>>>>>>>>>>>>
void myKeyboard(unsigned char theKey, int mouseX, int mouseY) {
    switch (theKey)
    {
    case 'P':
    case 'p':
        point();
        break;
    case 'L':
    case 'l':
        line();
        break;
    case 'T':
    case 't':
        triangle();
        break;
    case 'S':
    case 's':
        square();
        break;
    case 'H':
    case 'h':
        hexagon();
        break;
    case 'C':
    case 'c':
        circle(0.0,0.0,0.0,1.0);
        break;
    case 'U':
    case 'u':
        cube();
        break;
    case 'Q':
    case 'q':
        exit(-1);

    default:
        break;
    }
}
//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Eric Blanco - Assignment S1 - Type Q or q to quit");
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutKeyboardFunc(myKeyboard);
    myInit();
    glutMainLoop();
}