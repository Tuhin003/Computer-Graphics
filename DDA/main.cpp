
#include<iostream>
#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
using namespace std;
float x1Send,x2Send,y1Send,y2Send;
void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, x2Send+100, 0, y2Send+100);
}
void DDA(float x1,float x2,float y1,float y2)
{
    float dx;
float dy;
float m;
dx=x2-x1;
dy=y2-y1;
m=dy/dx;



if(m<1)
{
while(x1<=x2 && y1<=y2)
{
    x1=x1+1;
    y1=y1+m;
    glBegin(GL_POINTS);
    glVertex2i(x1,y1);


}
}
else if(m>1)
{
    while(x1<=x2 && y1<=y2)
{
    x1=x1+(1/m);
    y1=y1+1;
    glBegin(GL_POINTS);
   glVertex2i(x1,y1);

}
}
else if(m=1)
{
while(x1<=x2 && y1<=y2)
{
    x1=x1+1;
    y1=y1+1;
    glBegin(GL_POINTS);
    glVertex2i(x1,y1);

}
}
glEnd();
glFlush ();

}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



    glColor3f(1.0, 1.0, 0.0);
    DDA(x1Send, x2Send, y1Send, y2Send);

    glFlush();
}

int main(int argc, char *argv[])
{
    cout<< "Enter the value of x1Send : ";
    cin>>x1Send;
    cout<< "Enter the value of x2Send : ";
    cin>>x2Send;
    cout<< "Enter the value of y1Send : ";
    cin>>y1Send;
    cout<< "Enter the value of y2Send : ";
    cin>>y2Send;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(500, 500);
    glutCreateWindow("DDA");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

