#include<GL/gl.h>
#include <GL/glut.h>
#include<iostream>
using namespace std;
int x1Send,x2Send,y1Send,y2Send;
void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, x2Send+200, 0, y2Send+200);
}

void midPoint(int x1, int y1, int x2, int y2)
{


    int slope=1;
    int dx, dy, d,dk, x, y,yPrev;

    dx = x2 - x1;
    dy = y2 - y1;

    d = 2 * dy - dx;
    //dk = d + 2*dy - 2*dx* dy;

    x=x1;
    y=y1;
    yPrev=y;
    if (d >= 0)
    {

        y += slope;
        x += slope;
    }
    else
    {
        x += slope;
    }

    //Points
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    cout<<x<<" "<<y<<endl;
    dk=d;

    for (; x<x2 && y<y2;) {
        dk = dk + 2*dy - 2*dx*(y-yPrev);

        if(dk>=0)
        {
            yPrev=y;
            x++;
            y++;
        }
        else
        {
            x++;
            yPrev=y;
        }
        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();
        cout<<x<<" "<<y<<endl;

    }

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



    glColor3f(1.0, 1.0, 0.0);
    midPoint(x1Send, x2Send, y1Send, y2Send);

    glFlush();
}

int main(int argc, char *argv[])
{
    cin>>x1Send;
    cin>>x2Send;
    cin>>y1Send;
    cin>>y2Send;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham\'s midpoint line algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}





