//Eric Blanco
#include <math.h>
#include <Windows.h>
#include <GL\glew.h> //different includes necessary for my machine
#include <GL\freeglut.h>
#include <iostream>
#include <stdlib.h>

// Constants
#define PI 3.14159265358979324
static int width;
static int height;

//prototypes
void Shapes();
void myInit();

void myInit() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.5, 1.5, -2.5, 2.5, -3.5, 3.5);
}

//<<<<<<<<<<<<<<<<<<<<<<<<<display and 4 viewports>>>>>>>>>>>>>>>>
static void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);

    glViewport(0, 0, width / 2, height / 2);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, -3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    Shapes();

    glViewport(width / 2, 0, width / 2, height / 2);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    Shapes();

    glViewport(0, height / 2, width / 2, height / 2);
    glLoadIdentity();
    gluLookAt(0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0);
    Shapes();

    glViewport(width / 2, height / 2, width / 2, height / 2);
    glLoadIdentity();
    gluLookAt(0.0, -3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0);
    Shapes();

    glFlush();
}

//<<<<<<<<<<<<<<<<<<<<<<<< Shapes >>>>>>>>>>>>>>>>>
void point() {
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.15f, 0.10f);
    glVertex3f(0.0, 0.0, 0.0);
    glEnd();
    glFlush();
    //glutPostRedisplay();
}

void line() {
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5f, 0.0f, 0.75f);
    glVertex3f(-1.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, -1.0, 0.0);
    glEnd();
    glFlush();
    //glutPostRedisplay();
}

void triangle() {
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0, -1.0, 0.0);
    glVertex3f(1.0, -1.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    glEnd();
    glFlush();
    //glutPostRedisplay();
}

void square() {
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(-1.0, 1.0, 0.0); // top left
    glVertex3f(1.0, 1.0, 0.0); // top right 
    glVertex3f(1.0, -1.0, 0.0); // bottom right
    glVertex3f(-1.0, -1.0, 0.0); // bottom left
    glEnd();
    glFlush();
    //glutPostRedisplay();
}

void octagon() {
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.5f);
    glNormal3f(0.2, 0.2, 0.2);
    glVertex3f(-0.375, 0.75, 0.0); // top left
    glVertex3f(0.375, 0.75, 0.0); // top right 
    glVertex3f(0.75, 0.375, 0.0); // upper right
    glVertex3f(0.75, -0.375, 0.0); // lower right
    glVertex3f(0.375, -0.75, 0.0); // bottom right
    glVertex3f(-0.375, -0.75, 0.0); // bottom left
    glVertex3f(-0.75, -0.375, 0.0); // lower left
    glVertex3f(-0.75, 0.375, 0.0); // upper left
    glEnd();
    glFlush();
    //glutPostRedisplay();
}

void circle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius) {
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
    //glutPostRedisplay();
}

void cube() {
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_QUADS);
    //back
    glColor3f(0.0f, 0.0f, 0.5f);
    glNormal3f(0.225, 0.225, 0.225);
    glVertex3f(0.25, 0.25, 0.25);
    glVertex3f(-0.25, 0.25, 0.25);
    glVertex3f(-0.25, -0.25, 0.25);
    glVertex3f(0.25, -0.25, 0.25);
    //front
    glColor3f(0.0f, 0.0f, 0.6f);
    glNormal3f(0.225, 0.225, 0.225);
    glVertex3f(0.25, -0.25, -0.25);
    glVertex3f(-0.25, -0.25, -0.25);
    glVertex3f(-0.25, 0.25, -0.25);
    glVertex3f(0.25, 0.25, -0.25);
    //left
    glColor3f(0.0f, 0.0f, 0.7f);
    glNormal3f(0.225, 0.225, 0.225);
    glVertex3f(-0.25, 0.25, 0.25);
    glVertex3f(-0.25, 0.25, -0.25);
    glVertex3f(-0.25, -0.25, -0.25);
    glVertex3f(-0.25, -0.25, 0.25);
    //right
    glColor3f(0.0f, 0.0f, 0.8f);
    glNormal3f(0.225, 0.225, 0.225);
    glVertex3f(0.25, 0.25, -0.25);
    glVertex3f(0.25, 0.25, 0.25);
    glVertex3f(0.25, -0.25, 0.25);
    glVertex3f(0.25, -0.25, -0.25);
    //top
    glColor3f(1.0f, 0.0f, 0.9f);
    glNormal3f(0.225, 0.225, 0.225);
    glVertex3f(0.25, 0.25, -0.25);
    glVertex3f(-0.25, 0.25, -0.25);
    glVertex3f(-0.25, 0.25, 0.25);
    glVertex3f(0.25, 0.25, 0.25);
    //bottom
    glColor3f(0.0f, 1.0f, 0.0f);
    glNormal3f(0.225, 0.225, 0.225);
    glVertex3f(0.25, -0.25, 0.25);
    glVertex3f(-0.25, -0.25, 0.25);
    glVertex3f(-0.25, -0.25, -0.25);
    glVertex3f(0.25, -0.25, -0.25);
    glEnd();
    glFlush();
}

void sphere() {
    glColor3f(0.21, 0.48, 0.74);
    int color = 0;
    float pi = atan(1.0) * 4.0;
    float a, b, x, y, z;
    float da = 6.0, db = 6.0;
    float radius = 1.0;
    for (a = -90.0; a + da <= 90.0; a += da) {
        glBegin(GL_QUAD_STRIP);
        glNormal3f(0.25, 0.25, 0.25);
        glColor3f(0, 0, 0);
        for (b = 0.0; b <= 360.0; b += db) {
            if (color) {
                glColor3f(1.0, 0.0, 0.0);
            }
            else {
                glColor3f(1.0, 1.0, 1.0);
            }
            x = radius * cos(b * pi / 180) * cos(a * pi / 180);
            y = radius * sin(b * pi / 180) * cos(a * pi / 180);
            z = radius * sin(a * pi / 180);
            glVertex3f(x, y, z);
            x = radius * cos(b * pi / 180) * cos((a + da) * pi / 180);
            y = radius * sin(b * pi / 180) * cos((a + da) * pi / 180);
            z = radius * sin((a + da) * pi / 180);
            glVertex3f(x, y, z);
            color = 1 - color;
        }
        glEnd();
    }
    glFlush();
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>

void Shapes() {
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Point:
    glPushMatrix();
    glTranslatef(0.0, 0.7, 0.3);
    glScalef(0.25, 0.25, 0.25);
    glShadeModel(GL_FLAT);
    point();
    glPopMatrix();

    //Line:
    glPushMatrix();
    glTranslatef(-0.7, 0.7, 0.1);
    glScalef(0.25, 0.25, 0.25);
    glRotatef(72.0, 1.0, 0.0, 1.0);
    glShadeModel(GL_FLAT);
    line();
    glPopMatrix();

    //Triangle:
    glPushMatrix();
    glTranslatef(-0.7, 0.0, 0.45);
    glScalef(0.2, 0.2, 0.2);
    glRotatef(144.0, 0.0, 0.0, 1.0);
    glShadeModel(GL_FLAT);
    triangle();
    glPopMatrix();

    //Square:
    glPushMatrix();
    glTranslatef(-0.7, -0.7, 0.78);
    glScalef(0.2, 0.2, 0.2);
    glRotatef(144.0, 1.0, 1.0, 0.0);
    glShadeModel(GL_FLAT);
    square();
    glPopMatrix();

    //Octagon
    glPushMatrix();
    glTranslatef(0.0, -0.7, 0.12);
    glScalef(0.25, 0.25, 0.25);
    glRotatef(225.0, 1.0, 1.0, 0.0);
    glShadeModel(GL_FLAT);
    octagon();
    glPopMatrix();

    //Circle:
    glPushMatrix();
    glTranslatef(0.7, -0.7, 0.88);
    glScalef(0.2, 0.2, 0.2);
    glRotatef(360.0, 1.0, 1.0, 1.0);
    glShadeModel(GL_FLAT);
    circle(1, 1, 1, 0.5);
    glPopMatrix();

    //Cube 1:
    glPushMatrix();
    glTranslatef(0.7, 0.0, 0.58);
    glScalef(0.25, 0.25, 0.25);
    glRotatef(45.0, 1.0, 1.0, 1.0);
    glRotatef(360.0, 1.0, 1.0, 1.0);
    glRotatef(360.0, 1.0, 1.0, 1.0);
    glShadeModel(GL_SMOOTH);
    cube();
    glPopMatrix();

    //2nd cube:
    glPushMatrix();
    glTranslatef(0.7, 0.7, 0.24);
    glScalef(0.25, 0.25, 0.25);
    glRotatef(45.0, 1.0, 1.0, 1.0);
    glRotatef(360.0, 1.0, 1.0, 1.0);
    glRotatef(360.0, 1.0, 1.0, 1.0);
    glShadeModel(GL_SMOOTH);
    cube();
    glPopMatrix();

    //sphere
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.65);
    glScalef(0.25, 0.25, 0.25);
    glRotatef(270.0, 1.0, 1.0, 1.0);
    glShadeModel(GL_SMOOTH);
    sphere();
    glPopMatrix();
}

//<<<<<<<<<<<<<<<<<<<<<<<< myKeyboard >>>>>>>>>>>>>>
void myKeyboard(unsigned char theKey, int mouseX, int mouseY) {
    switch (theKey)
    {
    case 'Q':
    case 'q':
        exit(-1);

    default:
        break;
    }
}

//<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>
static void reshape(int w, int h) {
    width = w;
    height = h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

//<<<<<<<<<<<<<<<<<<<<main>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(240, 0);
    glutCreateWindow("Eric Blanco - S3 - (Q or q to quit)");
    glClearColor(0.35, 0.35, 0.35, 0.0);
    glShadeModel(GL_FLAT);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    //myInit();
    glutKeyboardFunc(myKeyboard);
    glutMainLoop();
}
