#include <bits/stdc++.h>
#include <stdio.h>
#include <GL/glut.h>
#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;
#define b1 first.first
#define b2 first.second
#define b3 second.first
#define b4 second.second
#define s second
#define f first
#define pb push_back
typedef long long int ll;
typedef pair<double,double> pd;   //pd is similar to points
typedef pair<bool,bool> pb;
typedef pair<pb,pb> pbb;
const int mx=1e6;


double x_minimum,x_maximum,y_minimum,y_maximum;
vector<vector<pd>> ar,res;
vector<pd> temp;
vector<vector<pbb>> bit;

void liang(void){

    int i,j;
    for(i=0;i<ar.size();i++)
    {

            double y1=ar[i][0].s,y2=ar[i][1].s;
            double x1=ar[i][0].f,x2=ar[i][1].f;
            double dy=y2-y1,dx=x2-x1;
            double p[4]={-1*dx,dx,-1*dy,dy},r[4],u1=0,u2=1;
            double q[4]={x1-x_minimum,x_maximum-x1,y1-y_minimum,y_maximum-y1};
             bool f=0;
            for(j=0;j<4;j++)
            {
                 if(p[j]==0&&q[j]<0)
                 {
                     f=1;break;
                 }
                 else if(p[j]<0)
                 {
                     r[j]=q[j]/p[j];
                     u1=max(u1,r[j]);
                 }
                 else if(p[j]>0)
                 {
                     r[j]=q[j]/p[j];
                     u2=min(u2,r[j]);
                 }

             }
             if(u1<=u2&&!f)
             {
                 ar[i][0].f=x1+dx*u1;
                 ar[i][0].s=y1+dy*u1;
                 ar[i][1].f=x1+dx*u2;
                 ar[i][1].s=y1+dy*u2;
                 res.push_back(ar[i]);
             }
        }
}


void draw_rect(int x)
{
    glBegin(GL_LINE_STRIP);
    glColor3ub(0,0,0);
    glVertex2d(x_minimum+x,y_minimum);
    glVertex2d(x_minimum+x,y_maximum);
    glVertex2d(x_maximum+x,y_maximum);
    glVertex2d(x_maximum+x,y_minimum);
    glVertex2d(x_minimum+x,y_minimum);
    glEnd();
}
void drawlines()
{
    for(int i =0;i<ar.size();i++)
    {
        glBegin(GL_LINE_STRIP);
        glColor3ub(255, 255, 55);
        glVertex2d(ar[i][0].f,ar[i][0].s);
        glVertex2d(ar[i][1].f,ar[i][1].s);
        glEnd();
	}
}
void drawline_res(int x)
{
    for(int i =0;i<res.size();i++)
    {
        glBegin(GL_LINE_STRIP);
        glColor3ub(255, 255, 55);
        glVertex2d(res[i][0].f+x,res[i][0].s);
        glVertex2d(res[i][1].f+x,res[i][1].s);
        glEnd();
	}
}

void liang_barsky(){

             drawlines();
             draw_rect(0);
             liang();
             drawline_res(2000);
             draw_rect(2000);
}
void DisplayFunction(void)
{
        liang_barsky();
        glFlush();
        glutPostRedisplay();
        glutSwapBuffers();
}
void initialization(void)
{
	glClearColor(.9, 0.3, .9, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-200.0, 4000.0, -1000.0, 2000.0);
}
int main(int argc, char** argv)
{
    int i,j,n,l;

    cout<<"Enter the clipper window's x_minimum y_minimum x_maximum y_maximum\n";
    cin>>x_minimum>>y_minimum>>x_maximum>>y_maximum;

    cout<<"Enter the number of shapes\n";
    cin>>n;

    for (i=0; i<n; i++)
    {
        cout<<"Enter the number of verteces: \n";
        cout<<"Enter the points: (x,y) \n";
        cin>>l;
        pd point;
        vector<pd> shape;
        for(j=0;j<l;j++)
        {
            cin>>point.f>>point.s;
            shape.pb(point);
        }
        ar.pb(shape);
    }
    temp=ar[0];
  	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(2000, 2000);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("Clipping");
	glutDisplayFunc(DisplayFunction);
	initialization();
	glutMainLoop();
//  return 0;
}
/*
100 100 1000 1000
5
2
300 1100
1200 300

2
700 800
250 200
2
0 0
1000 1000
2
60 40
780 420
2
500 500
1100 600
polygon best case
100 200 1000 800
1
3
300 700
200 -100
700 0

*/
