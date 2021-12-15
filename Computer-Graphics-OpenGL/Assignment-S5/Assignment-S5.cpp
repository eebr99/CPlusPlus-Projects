//Eric Blanco
#include <math.h>
#include <Windows.h>
#include <GL\glew.h> //different includes necessary for my machine
#include <GL\freeglut.h>
#include <iostream>
#include <stdlib.h>

const int windowHeight = 1024;
const int windowWidth = 1024;
const int viewportHeight = 512;
const int viewportWidth = 512;
const float pi = 3.1415922654;
const float rad = 1.5;
const float nGonSides = 40.0;
const float ngon = 2 * pi / nGonSides;

/*GLfloat ctrlpoints1[4][3] = {
		{ -2.0, -0.5, 0.0}, { -1.0, 0.5, 0.0},
		{1.0, -2.0, 0.0}, {2.0, 2.0, 0.0} };
*/
GLfloat ctrlpoints2[4][3] = {
		{ 4.0, -1.0, 0.0}, { -2.0, 1.0, 0.0},
		{2.0, -4.0, 0.0}, {4.0, 4.0, 0.0} };

/*GLfloat ctrlpoints3[4][3] = {
		{ -1.0, -1.0, 0.0}, { -2.0, 1.0, 0.0},
		{2.0, -4.0, 0.0}, {4.0, 4.0, 0.0} };
		*/
void exit(int);

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glShadeModel(GL_FLAT);
	//glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints3[0][0]);
	//glEnable(GL_MAP1_VERTEX_3);
	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints2[0][0]);
	glEnable(GL_MAP1_VERTEX_3);
	glPointSize(4.0);
	glLineWidth(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(222, 222, viewportWidth, viewportHeight);
	glFrustum(-3, 3, -3, 3, 1, 7);
	gluLookAt(0.125, 0.125, 0, 0, 0, 1, 0, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void pDisplay(void)
{
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POINTS);
	glVertex3f(0.0, 0.0, 0.0);
	glEnd();
	glFlush();
}

void lDisplay(void)
{
	glColor3f(0.0f, 0.2f, 0.0f);
	glBegin(GL_LINES);
	glVertex3f(-1.0, 0.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);
	glEnd();
	glFlush();
}

void tDisplay(void)
{
	glColor3f(0.0f, 0.4f, 0.0f);
	glBegin(GL_TRIANGLES);
	glVertex3f(-1.0, -.866, 0.0);
	glVertex3f(1.0, -.866, 0.0);
	glVertex3f(0.0, .866, 0.0);
	glEnd();
	glFlush();
}

void sDisplay(void)
{
	glColor3f(0.0f, 0.6f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(-1.0, -1.0, 0.0);
	glVertex3f(1.0, -1.0, 0.0);
	glVertex3f(1.0, 1.0, 0.0);
	glVertex3f(-1.0, 1.0, 0.0);
	glEnd();
	glFlush();
}

void oDisplay(void)
{
	glColor3f(0.0f, 0.8f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(-1.0, 0.0, 0.0);
	glVertex3f(-0.707, -0.707, 0.0);
	glVertex3f(0.0, -1.0, 0.0);
	glVertex3f(0.707, -0.707, 0.0);
	glVertex3f(1.0, 0.0, 0.0);
	glVertex3f(0.707, 0.707, 0.0);
	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(-0.707, 0.707, 0.0);
	glEnd();
	glFlush();
}

void cDisplay(void) {

	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
	for (float u = -pi; u <= pi; u += ngon) {
		glVertex3f(rad * cos(u), rad * sin(u), 0.0);
	}
	glEnd();
	glFlush();
}

void uDisplay(void)
{
	typedef GLfloat point3D[3];

	point3D vertices[8] = { {-0.125, 0.125, 0.125}, {0.125, 0.125, 0.125},
	 {0.125, 0.125, -0.125}, {-0.125, 0.125, -0.125}, {-0.125, -0.125, 0.125},
	 {0.125, -0.125, 0.125}, {0.125, -0.125, -0.125}, {-0.125, -0.125, -0.125} };



	glColor3f(0.5f, 0.5f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3fv(vertices[7]);
	glVertex3fv(vertices[4]);
	glVertex3fv(vertices[0]);
	glVertex3fv(vertices[3]);
	glEnd();

	glColor3f(0.6f, 0.6f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3fv(vertices[6]);
	glVertex3fv(vertices[7]);
	glVertex3fv(vertices[3]);
	glVertex3fv(vertices[2]);
	glEnd();

	glColor3f(0.7f, 0.7f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3fv(vertices[0]);
	glVertex3fv(vertices[1]);
	glVertex3fv(vertices[2]);
	glVertex3fv(vertices[3]);
	glEnd();

	glColor3f(0.8f, 0.8f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3fv(vertices[4]);
	glVertex3fv(vertices[5]);
	glVertex3fv(vertices[6]);
	glVertex3fv(vertices[7]);
	glEnd();

	glColor3f(0.9f, 0.9f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3fv(vertices[4]);
	glVertex3fv(vertices[5]);
	glVertex3fv(vertices[1]);
	glVertex3fv(vertices[0]);
	glEnd();

	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex3fv(vertices[5]);
	glVertex3fv(vertices[6]);
	glVertex3fv(vertices[2]);
	glVertex3fv(vertices[1]);
	glEnd();

	glFlush();
}

// new function for curves
//void curve1() {
	//glColor3f(0.52, 0.05, 0.23);
	//glBegin(GL_LINE_STRIP);
	//for (int i = 0; i <= 30; i++)
		//glEvalCoord1f((GLfloat)i / 30.0);
	//glEnd();
	/* The following code displays the control points as dots. */
	//glPointSize(5.0);
	//glColor3f(1.0, 1.0, 0.0);
	//glBegin(GL_POINTS);
	//for (int i = 0; i < 4; i++)
		//glVertex3fv(&ctrlpoints1[i][0]);
	//glEnd();
	//glFlush();
//}

void curve2() {
	glColor3f(0.22, 0.05, 0.23);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= 30; i++)
		glEvalCoord1f((GLfloat)i / 30.0);
	glEnd();
	/* The following code displays the control points as dots. */
	glPointSize(5.0);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POINTS);
	for (int i = 0; i < 4; i++)
		glVertex3fv(&ctrlpoints2[i][0]);
	glEnd();
	glFlush();
}

//void curve3() {
	//glColor3f(0.52, 0.05, 0.98);
	//glBegin(GL_LINE_STRIP);
	//for (int i = 0; i <= 30; i++)
		//glEvalCoord1f((GLfloat)i / 30.0);
	//glEnd();
	/* The following code displays the control points as dots. */
	//glPointSize(5.0);
	//glColor3f(1.0, 1.0, 0.0);
	//glBegin(GL_POINTS);
	//for (int i = 0; i < 4; i++)
		//glVertex3fv(&ctrlpoints3[i][0]);
	//glEnd();
	//glFlush();
//}

void theScene(void) {

	glClear(GL_COLOR_BUFFER_BIT);

	//point 
	glPushMatrix();
	glScalef(2.5, 2.5, 2.5);
	glTranslatef(0.5, 1.5, 1.0);
	pDisplay();
	glPopMatrix();

	//line 
	glPushMatrix();
	glScalef(3.5, 3.5, 3.5);
	glRotatef(45.0, 0.0, 1.0, 1.0);
	glTranslatef(-1.0, 2.0, 1.0);
	lDisplay();
	glPopMatrix();

	//triangle 
	glPushMatrix();
	glScalef(0.8, 0.8, 0.8);
	glRotatef(15.0, 1.0, 1.0, 1.0);
	glTranslatef(2.0, -2.0, 2.5);
	tDisplay();
	glPopMatrix();

	//square 
	glPushMatrix();
	glScalef(0.7, 0.7, 0.7);
	glRotatef(30.0, 1.0, 0.0, 0.0);
	glTranslatef(-1.5, -1.0, 2.5);
	sDisplay();
	glPopMatrix();

	//circle 
	glPushMatrix();
	glScalef(0.6, 0.8, 1.0);
	glRotatef(60.0, 1.0, 0.0, 1.0);
	glTranslatef(0.5, 2.5, 2.0);
	cDisplay();
	glPopMatrix();

	//octogon 
	glPushMatrix();
	glScalef(0.3, 0.7, 1.1);
	glRotatef(75.0, 0.0, 0.0, 1.0);
	glTranslatef(0.5, 5, 1.0);
	oDisplay();
	glPopMatrix();

	//cubes 
	glPushMatrix();
	glScalef(5.0, 5.0, 5.0);
	glTranslatef(1.0, -0.5, 1.0);
	glRotatef(45.0, 1.0, 1.0, 1.0);
	uDisplay();
	glTranslatef(0.75, 1.0, 1.0);
	uDisplay();
	glPopMatrix();
	
	//curves
	//glPushMatrix();
	//curve1();
	//glPopMatrix();

	glPushMatrix();
	curve2();
	glPopMatrix();

	//glPushMatrix();
	//curve3();
	//glPopMatrix();
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

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-5.0, 5.0, -5.0 * (GLfloat)h / (GLfloat)w,
			5.0 * (GLfloat)h / (GLfloat)w, -5.0, 5.0);
	else
		glOrtho(-5.0 * (GLfloat)w / (GLfloat)h,
			5.0 * (GLfloat)w / (GLfloat)h, -5.0, 5.0, -5.0, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int  main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(300, 0);
	glViewport(256, 256, viewportWidth, viewportHeight);
	glutCreateWindow("Eric Blanco - Assignment S5");
	glutDisplayFunc(theScene);
	glutReshapeFunc(reshape);
	myInit();
	glutKeyboardFunc(myKeyboard);
	glutMainLoop();
}
