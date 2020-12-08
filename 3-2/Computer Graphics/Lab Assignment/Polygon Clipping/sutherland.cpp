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


typedef enum
{
    Top,Bottom, Left, Right
} side;


bool get_stat(pd p , side e)
{
    if(e==Left&& p.f < x_minimum)
            return 0;
   else if(e==Right&& p.f > x_maximum)
            return 0;
   else if(e==Top&& p.s > y_maximum)
            return 0;
   else if(e==Bottom&& p.s < y_minimum)
            return 0;
    return 1;
}

pd Intersect(vector<pd> line, side e)
{
    double x,y;

    switch(e)
    {
    case Left :
        y = line[0].s + ((line[1].s-line[0].s)*(x_minimum-line[0].f))/(line[1].f-line[0].f);
        x = x_minimum;
        break;
    case Right :
        y = line[0].s + ((line[1].s-line[0].s)*(x_maximum-line[0].f))/(line[1].f-line[0].f);
        x = x_maximum;
        break;
    case Top :
        x = line[0].f + ((line[1].f-line[0].f)*(y_maximum-line[0].s))/(line[1].s - line[0].s);
        y = y_maximum;
        break;
    case Bottom :
        x = line[0].f + ((line[1].f-line[0].f)*(y_minimum-line[0].s))/(line[1].s - line[0].s);
        y = y_minimum;
        break;
    }
    return make_pair(x,y);
}
void suther(void)
{
      res=ar;
    for (int e=1;e<2;e++)  //1 edge
    {
                            // only oneside works at a time
                            //because of while calculating line there create devided by zero

        side ee=(side)e;
        int j,k=0;
        vector<pd> tmp;

        for(j=0;j<=res[k].size();j++)
        {
            pd p1=res[k][j];
            pd p2=res[k][(j+1)%ar[k].size()];
            bool c1= get_stat(p1,ee);
            bool c2= get_stat(p2,ee);
            vector<pd> line;
            line.push_back(p1);
            line.push_back(p2);
            if(c1&&c2) //both inside i i
             tmp.push_back(p2); //second one pushed
            else if(c1&&!c2) // inside-outside
                tmp.push_back(Intersect(line,ee));
            else if(!c1&&c2)  //outside-inside
            {
                tmp.push_back(Intersect(line,ee));
                tmp.push_back(p2);
            }
        }
        res[k].clear();
        res[k]=tmp;
    }

}
void draw_poly(int x)
{
    glBegin(GL_POLYGON);
	glColor3ub(235, 105, 105);
	for(int j=0;j<ar[0].size();j++)
	glVertex2d(ar[0][j].f+x,ar[0][j].s);
	glEnd();
}
void draw_polyres(int x)
{
    glBegin(GL_POLYGON);

    glColor3ub(255, 255, 55);
	for(int j=0;j<res[0].size();j++)
	glVertex2d(res[0][j].f+x,res[0][j].s);
	glEnd();
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

void sutherland_hodg()
{
             draw_poly(0);
             draw_rect(0);
             suther();  ///these function also needed: get_stat() , Intersect()
             draw_polyres(2000);
             draw_rect(2000);
}
void DisplayFunction(void)
{
	    sutherland_hodg();
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
polygon best case
100 200 1000 800
1
3
300 700
200 -100
700 0

*/
