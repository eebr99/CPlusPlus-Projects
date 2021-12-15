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
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.15f, 0.10f);
    glVertex3f(0.0, 0.0, 0.0);
    glEnd();
    glFlush();
    glutPostRedisplay();
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
    glutPostRedisplay();
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
    glutPostRedisplay();
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
    glutPostRedisplay();
}

void hexagon() {
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.5f);
    glVertex3f(-0.75, 2.0, 0.0); // top left // points so that edges = 1.5 
    glVertex3f(0.75, 2.0, 0.0); // top right 
    glVertex3f(1.40, 0.5, 0.0); //center right 1
    glVertex3f(1.40, -0.5, 0);// center right 2
    glVertex3f(0.75, -2.0, 0.0); // bottom right
    glVertex3f(-0.75, -2.0, 0.0); // bottom left
    glVertex3f(-1.40, 0.5, 0.0); // center left 1
    glVertex3f(-1.40, -0.5, 0.0); //center left 2
    glEnd();
    glFlush();
    glutPostRedisplay();
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
    glutPostRedisplay();
}

void cube() {
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.5f);
    glBegin(GL_POLYGON);
    glVertex3f(-1.4142, -0.9848, -0.1736);
    glVertex3f(0.0, -0.7392, 1.5664);
    glVertex3f(0.0, 1.2305, 1.219);
    glVertex3f(-1.4142, 0.9848, 0.1736);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.6f);
    glBegin(GL_POLYGON);
    glVertex3f(0.0, -0.7392, 1.5664);
    glVertex3f(1.4142, -0.9848, -0.1736);
    glVertex3f(1.4142, 0.9848, 0.1736);
    glVertex3f(0.0, 1.2305, 1.219);
    glEnd();
    
    glColor3f(0.0f, 0.0f, 0.7f);
    glBegin(GL_POLYGON);
    glVertex3f(-1.4142, -0.9848, -0.1736);
    glVertex3f(0.0, -1.2305, -1.219);
    glVertex3f(1.4142, -0.9848, -0.1736);
    glVertex3f(0.0, -0.7392, 1.5664);
    glEnd();
    
    glColor3f(0.0f, 0.0f, 0.8f);
    glBegin(GL_POLYGON);
    glVertex3f(-1.4142, -0.9848, -0.1736);
    glVertex3f(0.0, -1.2305, -1.219);
    glVertex3f(0.0, 0.7392, -1.5664);
    glVertex3f(-1.4142, 0.9848, 0.1736);
    glEnd();
    
    glColor3f(1.0f, 0.0f, 0.9f);
    glBegin(GL_POLYGON);
    glVertex3f(0.0, -1.2305, -1.219);
    glVertex3f(1.4142, -0.9848, -0.1736);
    glVertex3f(1.4142, 0.9848, 0.1736);
    glVertex3f(0.0, 0.7392, -1.5664);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.4142, 0.9848, 0.1736);
    glVertex3f(0.0, 0.7392, -1.5664);
    glVertex3f(1.4142, 0.9848, 0.1736);
    glVertex3f(0.0, 1.2305, 1.219);
    glEnd();
    
    glFlush();
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

void render(void)
{
    //glClearColor(1.0, 1.0, 1.0, 0.0);
    //glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.5, 1.5, -2.5, 2.5, -3.5, 3.5);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Draw point
    glPushMatrix();
    glScalef(1.0, 1.0, 0.0);
    glTranslatef(1.0, 1.0, 0.0);
    point();
    glPopMatrix();

    // Draw line
    glPushMatrix();
    glScalef(1.0, 1.0, 2.0);
    glTranslatef(0.0, 0.0, 0.0);
    line();
    glPopMatrix();

    //draw triangle
    glPushMatrix();
    glTranslatef(1.25, 1.25, 0.0);
    glScalef(0.20, 0.20, 0.20);
    triangle();
    glPopMatrix();
    
    //draw square
    glPushMatrix();
    glTranslatef(1.5, -1.5, 0.0);
    glScalef(0.20, 0.10, 0.10);
    square();
    glPopMatrix();
    
    //draw hexagon
    glPushMatrix();
    glTranslatef(-1.25, 1.25, 0.0);
    glScalef(0.20, 0.10, 0.10);
    hexagon();
    glPopMatrix();
    
    //draw circle
    glPushMatrix();
    glTranslatef(-.25, -2.0, 0.0);
    glScalef(0.20, 0.10, 0.10);
    circle(1, 1, 1, .5);
    glPopMatrix();
    glutSwapBuffers();

    //draw cube 1
    glPushMatrix();
    glTranslatef(-1.25, -1.25, 0.0);
    glScalef(0.20, 0.10, 0.10);
    cube();
    glPopMatrix();

    //draw cube 2
    glPushMatrix();
    glTranslatef(-1.25, -2.25, 0.0);
    glScalef(0.20, 0.10, 0.10);
    cube();
    glPopMatrix();
}

//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Eric Blanco - Assignment S2 - Type Q or q to quit");
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutDisplayFunc(render);
    glutKeyboardFunc(myKeyboard);
    //myInit();
    //gluLookAt(0,0,0,0,0,0,0,0,0);
    glutMainLoop();
}