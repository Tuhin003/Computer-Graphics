#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>

GLfloat position = 0.0f;
GLfloat posi = 0.0f;
GLfloat rocket = 0.0f;


GLfloat speed = -0.1f;
GLfloat speed1 = 0.1f;


void update(int value) {

    if(position < -1.0)
        position = 1.2f;

    position += speed;

	glutPostRedisplay();
	glutTimerFunc(100, update, 0);
}

void update1(int value) {
	if(posi > 1.0)
    posi = -0.10f;




    posi += speed1;


	glutPostRedisplay();
	glutTimerFunc(100, update1, 0);


}
void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glMatrixMode(GL_PROJECTION);
   gluOrtho2D(-1.0, 1.0, -1.0, 1.0 );
}



void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

	//rocket
    case 'a':
    if(rocket<-0.9)
        rocket= -0.8f;
    rocket -= 0.01f;
    break;

case 'd':
    if(rocket<1)
          rocket += 0.01f;
    break;


 //bullet
case 'm':
    speed1 = 0.0f;
    break;
case 's':
    speed1 += 0.1f;
    break;


glutPostRedisplay();


	}
}

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glLoadIdentity();

glPushMatrix();
glTranslatef(0.0f,position, 0.0f);

//YELLOW TRIANGLE
glBegin(GL_TRIANGLES);
glColor3ub (255, 255, 0);
glVertex2f(-0.8, 0.6);
glVertex2f(-0.65, 0.6);
glVertex2f(-0.72, 0.8);
glEnd();

//RED TRIANGLE

glColor3ub (255, 0, 0);
glBegin(GL_TRIANGLES);
glVertex2f(-0.25, 0.85);
glVertex2f(-0.10, 0.85);
glVertex2f(-0.178, 0.95);
glEnd();

//GREEN TRIANGLE

glColor3ub (0, 250,154);
glBegin(GL_TRIANGLES);
glVertex2f(0.8, 0.7);
glVertex2f(0.65, 0.7);
glVertex2f(0.72, 0.9);
glEnd();

glPopMatrix();




glPushMatrix();
glTranslatef(rocket,0.0f, 0.0f);

//WHITE ROCKET
glColor3ub (255, 255, 255);
glBegin(GL_TRIANGLES);
glVertex2f(0.1, 0.0);
glVertex2f(0.2, 0.0);
glVertex2f(0.15, 0.25);
glEnd();
//ROCKET QUADS
glColor3ub (255, 140, 0);
glBegin(GL_QUADS);

glVertex2f(0.2, 0.0);
glVertex2f(0.1, 0.0);
glVertex2f(0.1, -0.6);
glVertex2f(0.2, -0.6);
glEnd();

//ROCKET RIGHT TOP TRIANGLE

glColor3ub (204, 0, 0);
glBegin(GL_TRIANGLES);
glVertex2f(0.2, 0.0);
glVertex2f(0.2, -0.2);
glVertex2f(0.3, -0.2);
glEnd();



//ROCKET RIGHT DOWN TRIANGLE

glColor3ub (204, 0, 0);
glBegin(GL_TRIANGLES);
glVertex2f(0.2, -0.6);
glVertex2f(0.3, -0.6);
glVertex2f(0.2, -0.3);
glEnd();


//ROCKET LEFT TOP TRIANGLE

glColor3ub (204, 0, 0);
glBegin(GL_TRIANGLES);
glVertex2f(0.1, 0.0);
glVertex2f(0.0, -0.2);
glVertex2f(0.1, -0.2);
glEnd();


//ROCKET LEFT DOWN TRIANGLE

glColor3ub (204, 0, 0);
glBegin(GL_TRIANGLES);
glVertex2f(0.0, -0.6);
glVertex2f(0.1, -0.6);
glVertex2f(0.1, -0.3);
glEnd();


//ROCKET  DOWN POLYGON

glColor3ub (204, 0, 0);
glBegin(GL_POLYGON);

glVertex2f(0.2, -0.6);
glVertex2f(0.1, -0.6);
glVertex2f(0.0, -0.75);
glVertex2f(0.15, -0.95);
glVertex2f(0.3, -0.75);
glVertex2f(0.2, -0.6);
glEnd();
glTranslatef(0.0f,posi, 0.0f);

//BULLET
glColor3ub (0, 0, 255);
glBegin(GL_TRIANGLES);
glVertex2f(0.11, 0.25);
glVertex2f(0.18, 0.25);
glVertex2f(0.146, 0.3);
glEnd();


glPopMatrix();


glFlush ();
}

void myInit (void)
{
glClearColor(0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (640, 480);
glutInitWindowPosition (100, 150);
glutCreateWindow ("ROCKET GAME");
glutDisplayFunc(myDisplay);
myInit ();
glutKeyboardFunc(handleKeypress);

glutTimerFunc(1000, update, 0);
glutTimerFunc(1000, update1, 0);
glutMainLoop();
}
