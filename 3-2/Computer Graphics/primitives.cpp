/*
  points must be edited according to figure
*/
#include <windows.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;
double x1,x2,y1,y2;
void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // lines
//    glBegin(GL_LINES);
//    glColor3f(1.0,0.0,0.0);
//    glVertex3f(-60,140,0.0);
//    glVertex3f(-90,160,0.0);
//    glEnd();
    // line strip
//    glBegin(GL_LINE_STRIP);
//    glColor3f(1.0,0.0,0.0);
//    glVertex3f(-60,160,0.0);
//    glVertex3f(-40,160,0.0);
//    glVertex3f(-40,140,0.0);
//    glEnd();
    // line loop
//    glBegin(GL_LINE_LOOP);
//    glColor3f(1.0,0.0,0.0);
//    glVertex3f(-60,160,0.0);
//    glVertex3f(-40,260,0.0);
//    glVertex3f(-40,340,0.0);
//    glEnd();


    // triangles
//    glBegin(GL_TRIANGLES);
//    glColor3f(1.0,1.0,0.0);
//    glVertex3f(-60,160,0.0);
//    glVertex3f(-40,260,0.0);
//    glVertex3f(-140,340,0.0);
//    glEnd();

// triangles strip
//    glBegin(GL_TRIANGLE_STRIP);
//    glColor3f(1.0,1.0,0.0);
//    glVertex3f(-60,160,0.0);
//    glVertex3f(-40,260,0.0);
//    glVertex3f(-140,340,0.0);
//    glVertex3f(140,340,0.0);
//    glEnd();

// triangle fan
//    glBegin(GL_TRIANGLE_FAN);
//    glColor3f(1.0,1.0,0.0);
//    glVertex3f(-60,160,0.0);
//    glVertex3f(-40,260,0.0);
//    glVertex3f(-140,340,0.0);
//    glVertex3f(140,440,0.0);
//    glEnd();

// quads
//glBegin(GL_QUADS);
//    glColor3f(1.0,1.0,0.0);
//    glVertex3f(0,0,0);
//    glVertex3f(-100,100,0);
//    glVertex3f(-300,100,0);
//    glVertex3f(0,-200,0);
//    glEnd();

// quad strip

//    glBegin(GL_QUAD_STRIP);
//    glColor3f(1.0,1.0,0.0);
//    glColor3f(1.0,1.0,0.0);
//    glVertex3f(0,0,0);
//    glVertex3f(-100,100,0);
//    glVertex3f(-300,100,0);
//    glVertex3f(0,-200,0);
//    glVertex3f(200,-200,0);
//    glVertex3f(100,-100,0);
//    glEnd();

//    glBegin(GL_POLYGON);
//    glColor3f(1.0,1.0,0.0);
//    glVertex3f(108,10,0);
//    glVertex3f(70,100,0);
//    glVertex3f(60,100,0);
//    glVertex3f(500,10,0);
//    glVertex3f(500,-10,0);
//    glVertex3f(60,-20,0);
//    glVertex3f(70,-200,0);
//    glVertex3f(80,-100,0);
//    glEnd();
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

    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(350,100);
    glutInitDisplayMode(GLUT_RGB);

    glutCreateWindow("DDA Algo");

    init();
    glutDisplayFunc(draw);

    glutMainLoop();

    return 0;
}
/*0 0
400 400*/
