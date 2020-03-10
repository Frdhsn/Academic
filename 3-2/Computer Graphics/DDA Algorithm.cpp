/*
  Author: Farhad
  Date: 11/03/2020
*/
#include <windows.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;
double x1,x2,y1,y2;
void DDA()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);

    if(x1>x2){
        swap(x1,x2);
        swap(y1,y2);
    }
    int dx = x2 - x1;
    int dy = y2 - y1;

    int step = max(dx,dy);

    double m = (dy*1.0)/(dx*1.0);

    double x_inc = (dx*1.0)/(1.0*step);
    double y_inc = (dy*1.0)/(1.0*step);

    glBegin(GL_POINTS);
    glVertex3f(x1,y1,0.0);
    //cout<<fixed<<x1<<" "<<y1<<endl;
    for(int i=1;i<=step;i++){

        int xi = round( (double) (x1 + x_inc));
        int yi = round( (double) (y1 + y_inc));
        x1 =  (x1 + x_inc);
        y1 = (y1 + y_inc);

        //cout<<fixed<<xi<<" "<<yi<<endl;
        glVertex3f(xi,yi,0.0);
    }
    glEnd();
    glFlush();
}
void init()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500,500,-500,500);
}
int main(int argc, char *argv[])
{
    cout<<"Enter the first co-ordinate of end points:\n";
    cout<<"x1 = ";cin>>x1;
    cout<<"y1 = ";cin>>y1;
    cout<<"x2 = ";cin>>x2;
    cout<<"y2 = ";cin>>y2;
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(350,100);
    glutInitDisplayMode(GLUT_RGB);

    glutCreateWindow("DDA Algo");

    init();
    glutDisplayFunc(DDA);

    glutMainLoop();

    return 0;
}
