#include <GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float x,y,i;
float counter=0.0;
float counter2=0.0;
float counter3=0.0;
void clock(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
        glBegin(GL_TRIANGLE_FAN);
		glColor3ub(200,200,200);
		for(i=0;i<=2*3.14;i+=0.01)
		{
			x=0.65*sin(i);
			y=0.65*cos(i);
			glVertex2f(x,y);
		}
        glEnd();
        glBegin(GL_TRIANGLE_FAN);
		glColor3ub(0,160,255);
		for(i=0;i<=2*3.14;i+=0.01)
		{
			x=0.6*sin(i);
			y=0.6*cos(i);
			glVertex2f(x,y);
		}
        glEnd();
        glPushMatrix();
        glRotatef(counter,0.0,0.0,-1.0);
        counter+=0.007;
        glBegin(GL_LINES);
		glColor3ub(255,255,255);
		glVertex2f(0.0,0.0);
		glVertex2f(0,0.3);
        glEnd();
        glPopMatrix();
        glPushMatrix();
        glRotatef(counter2,0.0,0.0,-1.0);
        counter2+=0.1;
        glBegin(GL_LINES);
		glColor3ub(255,255,255);
		glVertex2f(0.0,0.0);
		glVertex2f(0.0,0.45);
		glEnd();
        glPopMatrix();
        glPushMatrix();
        glRotatef(counter3,0.0,0.0,-1.0);
        counter3+=1.5;
        glBegin(GL_LINES);
        glColor3ub(0,0,0);
		glVertex2f(0.0,0.0);
		glVertex2f(0.0,0.55);
    glEnd();
    glPopMatrix();
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);
		glColor3ub(211,211,211);
		for(i=0;i<=2*3.14;i+=0.0001)
		{
			x=0.03*sin(i);
			y=0.03*cos(i);
			glVertex2f(x,y);
		}
	glEnd();
    glPopMatrix();
	glutSwapBuffers();
}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowSize(640,480);
	glutCreateWindow("Clock");
	glutDisplayFunc(clock);
	glutIdleFunc(clock);
	glutMainLoop();
	return 0;
}
