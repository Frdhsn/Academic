#include <windows.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;
int x1,x2,y1,y2;

void BresenhamAlgo()
{
    glClear(GL_COLOR_BUFFER_BIT);

    int dx = x2 - x1;
    int dy = y2 - y1;
    int inc1 = 2*dx;
    int inc2 = 2*dx - 2*dy;

    int p = inc1 - dy;
    int x = x1;
    int y = y1;

    glBegin(GL_POINTS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(x,y,0.0);
    while(y<=y2){
            y++;
            if(p<0){
                p+=inc1;
                x++;
            }
            else{
                p+=inc2;
            }
            glVertex3f(x,y,0.0);
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

    if(x1>x2){
        swap(x1,x2);
        swap(y1,y2);
    }
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(350,100);
    glutInitDisplayMode(GLUT_RGB);

    glutCreateWindow("Bresenham Algo");

    init();
    glutDisplayFunc(BresenhamAlgo);

    glutMainLoop();

    return 0;
}
/*0 0
400 400*/
