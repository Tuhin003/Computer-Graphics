#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glClearColor(0.0, 0.0, 0.0, 0.0);
gluOrtho2D(0.0,8.0,0.0,8.0);
int i,d=1;
for(i=0;i<8;i++)
{
    if(d%2!=0)
    {
        glColor3ub(0,0,0);
    }
    else
    {
        glColor3ub(255,255,255);
    }
    d++;
    glBegin(GL_QUADS);
    glVertex2f(0,i);
    glVertex2f(0+1,i);
    glVertex2f(0+1,i+1);
    glVertex2f(0,i+1);
    glEnd();
}
d++;
for(i=0;i<8;i++)
{
    if(d%2!=0)
    {
        glColor3ub(0,0,0);
    }
    else
    {
        glColor3ub(255,255,255);
    }
    d++;
    glBegin(GL_QUADS);
    glVertex2f(1,i);
    glVertex2f(1+1,i);
    glVertex2f(1+1,i+1);
    glVertex2f(1,i+1);
    glEnd();
}
d++;
for(i=0;i<8;i++)
{
    if(d%2!=0)
    {
        glColor3ub(0,0,0);
    }
    else
    {
        glColor3ub(255,255,255);
    }
    d++;
    glBegin(GL_QUADS);
    glVertex2f(2,i);
    glVertex2f(2+1,i);
    glVertex2f(2+1,i+1);
    glVertex2f(2,i+1);
    glEnd();
}
d++;
for(i=0;i<8;i++)
{
    if(d%2!=0)
    {
        glColor3ub(0,0,0);
    }
    else
    {
        glColor3ub(255,255,255);
    }
    d++;
    glBegin(GL_QUADS);
    glVertex2f(3,i);
    glVertex2f(3+1,i);
    glVertex2f(3+1,i+1);
    glVertex2f(3,i+1);
    glEnd();
}
d++;

for(i=0;i<8;i++)
{
    if(d%2!=0)
    {
        glColor3ub(0,0,0);
    }
    else
    {
        glColor3ub(255,255,255);
    }
    d++;
    glBegin(GL_QUADS);
    glVertex2f(4,i);
    glVertex2f(4+1,i);
    glVertex2f(4+1,i+1);
    glVertex2f(4,i+1);
    glEnd();
}
d++;

for(i=0;i<8;i++)
{
    if(d%2!=0)
    {
        glColor3ub(0,0,0);
    }
    else
    {
        glColor3ub(255,255,255);
    }
    d++;
    glBegin(GL_QUADS);
    glVertex2f(5,i);
    glVertex2f(5+1,i);
    glVertex2f(5+1,i+1);
    glVertex2f(5,i+1);
    glEnd();
}
d++;
for(i=0;i<8;i++)
{
    if(d%2!=0)
    {
        glColor3ub(0,0,0);
    }
    else
    {
        glColor3ub(255,255,255);
    }
    d++;
    glBegin(GL_QUADS);
    glVertex2f(6,i);
    glVertex2f(6+1,i);
    glVertex2f(6+1,i+1);
    glVertex2f(6,i+1);
    glEnd();
}
d++;
for(i=0;i<8;i++)
{
    if(d%2!=0)
    {
        glColor3ub(0,0,0);
    }
    else
    {
        glColor3ub(255,255,255);
    }
    d++;
    glBegin(GL_QUADS);
    glVertex2f(7,i);
    glVertex2f(7+1,i);
    glVertex2f(7+1,i+1);
    glVertex2f(7,i+1);
    glEnd();
}
d++;

glFlush ();
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (640, 480);
glutInitWindowPosition (100, 150);
glutCreateWindow ("Chess Board");
glutDisplayFunc(myDisplay);
glutMainLoop();
}
