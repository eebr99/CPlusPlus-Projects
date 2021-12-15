//Eric Blanco
#include <math.h>
#include <Windows.h>
#include <GL\glew.h> //different includes necessary for my machine
#include <GL\freeglut.h>
#include <iostream>
#include <stdlib.h>
#define PI 3.1415927

/*<<<<<<<<<<<<<<<<<<<<<< PPM >>>>>>>>>>>>>>>>>>>>>>>>>>>
int n;
int m;
GLuint *image;
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glRasterPos2i(0,0);
    glDrawPixels(n,m,GL_RGB, GL_UNSIGNED_INT, image);
glFlush();
printf("finished display \n");
}
void myreshape(int h, int w)
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, (GLfloat) n, 0.0, (GLfloat) m);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glViewport(0,0,h,w);
}
int main(int argc, char **argv)
{
FILE *fd;
int  k, nm;
char c;
int i;
char b[100];
float s;
int red, green, blue;
printf("enter file name\n");
scanf("%s", b);
fd = fopen(b, "r");
fscanf(fd,"%[^\n] ",b);
if(b[0]!='P'|| b[1] != '3')
{
printf("%s is not a PPM file!\n", b);
exit(0);
}
printf("%s is a PPM file\n",b);
fscanf(fd, "%c",&c);
while(c == '#')
{
fscanf(fd, "%[^\n] ", b);
printf("%s\n",b);
fscanf(fd, "%c",&c);
}
ungetc(c,fd);
fscanf(fd, "%d %d %d", &n, &m, &k);
printf("%d rows  %d columns  max value= %d\n",n,m,k);
nm = n*m;
image==malloc(3*sizeof(GLuint)*nm);
s=255./k;
for(i=0;i<nm;i++)
{
fscanf(fd,"%d %d %d",&red, &green, &blue );
image[3*nm-3*i-3]=red;
image[3*nm-3*i-2]=green;
image[3*nm-3*i-1]=blue;
}
printf("read image\n");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize(n, m);
glutInitWindowPosition(0,0);
    glutCreateWindow("image");
glutReshapeFunc(myreshape);
    glutDisplayFunc(display);
glPixelTransferf(GL_RED_SCALE, s);
glPixelTransferf(GL_GREEN_SCALE, s);
glPixelTransferf(GL_BLUE_SCALE, s);
glPixelStorei(GL_UNPACK_SWAP_BYTES,GL_TRUE);
glClearColor(1.0, 1.0, 1.0, 1.0);
    glutMainLoop();
}
*/

//<<<<<<<<<<<<<<<<<<<<<<< walls >>>>>>>>>>>>>>>>>>>>>>>>
void wall(double thickness)    // function to create the walls with given thickness
{
    glPushMatrix();
    glTranslated(0.5, 0.5 * thickness, 0.5);
    glScaled(1.0, thickness, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();
}

void displaySolid() {
    GLfloat mat_ambient[] = { 0.7f,0.7f,0.7f,0.1f };
    GLfloat mat_diffuse[] = { 0.5f,0.5f,0.5f,1.0f };
    GLfloat mat_specular[] = { 1.0f,1.0f,1.0f,1.0f };
    GLfloat mat_shininess[] = { 50.0f };
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    GLfloat light_Intensity[] = { 0.7f,0.7f,0.7f,1.0f };
    GLfloat light_Position[] = { 2.0f,6.0f,3.0f,0.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, light_Position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_Intensity);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double winlet = 1.0;
    glOrtho(-winlet * 64 / 48, winlet * 64 / 48.0, -winlet * 64 / 48, winlet * 64 / 48, 0.6, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(2.3, 1.38, 2.0, 0.0, 0.25, 0.0, 0.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glTranslated(0.08, 0.08, 0.08);
    glPushMatrix();
    glTranslated(0.6, 0.38, 0.5);
    glRotated(30, 0, 1, 0);
    //glutSolidTeapot(0.08);
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.25, 0.42, 0.35);
    glPopMatrix();
    glPushMatrix();
    glTranslated(0.4, 0, 0.4);
    glPopMatrix();
    wall(0.1);
    glPushMatrix();
    glRotated(-90.0, 1.0, 0.0, 0.0);
    wall(0.02);
    glPopMatrix();
    glRotated(90.0, 0.0, 0.0, 180.0);
    wall(0.02);
    glPopMatrix();
    glFlush();
}
//<<<<<<<<<<<<<<<<<<<<<<< shapes >>>>>>>>>>>>>>>>>>>>>>>>>>>>>
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

void hexagon() {
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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


void cylinder(GLfloat radius, GLfloat height)
{
    GLfloat x = 0.0;
    GLfloat y = 0.0;
    GLfloat angle = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3f(0.25f, 0.85f, 1.0f);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI) {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, height);
        glVertex3f(x, y, 0.0);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glVertex3f(radius, 0.0, 0.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3f(0.25f, 0.85f, 1.0f);
    glBegin(GL_POLYGON);
    angle = 0.0;
    while (angle < 2 * PI) {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, height);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glEnd();
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>

void Shapes() {
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    displaySolid();

    //Triangle:
    glPushMatrix();
    glTranslatef(1.0, 1.0, 0.5);
    glScalef(0.1, 0.1, 0.1);
    glRotatef(144.0, 0.0, 0.0, 1.0);
    glShadeModel(GL_FLAT);
    triangle();
    glPopMatrix();

    //Square:
    glPushMatrix();
    glTranslatef(1.35, 0.59, 0.65);
    glScalef(0.17, 0.17, 0.17);
    glRotatef(144.0, 1.0, 1.0, 0.0);
    glShadeModel(GL_FLAT);
    square();
    glPopMatrix();

    //Hexagon
    glPushMatrix();
    glTranslatef(0.25, 1.0, 0.65);
    glScalef(0.1, 0.1, 0.1);
    glRotatef(225.0, 1.0, 1.0, 0.0);
    glShadeModel(GL_FLAT);
    hexagon();
    glPopMatrix();

    //Cube:
    glPushMatrix();
    glTranslatef(0.25, 0.28, 0.85);
    glScalef(0.25, 0.25, 0.25);
    glRotatef(45.0, 1.0, 1.0, 1.0);
    glRotatef(360.0, 1.0, 1.0, 1.0);
    glRotatef(360.0, 1.0, 1.0, 1.0);
    glShadeModel(GL_SMOOTH);
    cube();
    glPopMatrix();

    //Sphere
    glPushMatrix();
    glTranslatef(0.5, 0.73, 0.65);
    glScalef(0.15, 0.15, 0.15);
    glRotatef(270.0, 1.0, 1.0, 1.0);
    glShadeModel(GL_SMOOTH);
    sphere();
    glPopMatrix();

    //Cylinder
    glPushMatrix();
    //glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, -0.4, -2.0);
    glRotatef(-40, 1.0, 0.0, 0.0);
   //glScalef(0.15, 0.15, 0.15);
    cylinder(0.15, 0.5);
    glFlush();
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
//<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>.
void main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Eric Blanco - Assignment S4 - Type Q or q to quit");
    glutDisplayFunc(Shapes);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glClearColor(0.1, 0.1, 0.1, 0.0);
    glViewport(0, 0, 640, 480);
    glutKeyboardFunc(myKeyboard);
    glutMainLoop();
}
//end