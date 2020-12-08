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

pbb bit_cal(int x,int y)
{
         pbb tmp;
         tmp.b1=0;tmp.b2=0;tmp.b3=0;tmp.b4=0;
        if(y>y_maximum)
            tmp.b1=1;
        if(y<y_minimum)
            tmp.b2=1;
        if(x>x_maximum)
            tmp.b3=1;
        if(x<x_minimum)
            tmp.b4=1;
            return tmp;
}

int clipable(pbb i,pbb j)
{
    int sum=0,andsum=0;

        sum+=(i.b1+j.b1);
        andsum+=(i.b1&j.b1);

        sum+=(i.b2+j.b2);
        andsum+=(i.b2&j.b2);


        sum+=(i.b3+j.b3);
        andsum+=(i.b3&j.b3);

        sum+=(i.b4+j.b4);
        andsum+=(i.b4&j.b4);


    if(sum==0)
        return 0;
    else if(andsum==0)
        return 1;
    else
        return -1;
}

void drawline(vector<pd> l)
{

    glBegin(GL_LINE_STRIP);
	glColor3ub(255, 255, 55);
	glVertex2d(l[0].f+2000,l[0].s);
	glVertex2d(l[1].f+2000,l[1].s);
	glEnd();

}
void mid_point_clip(vector<pd> line)
{
    pbb a=bit_cal(line[0].f,line[0].s);
    pbb b=bit_cal(line[1].f,line[1].s);
    int clip=clipable(a,b);
    if(clip==0)
    {
        drawline(line);
    }
    else if(clip==-1)
        return;

    double midx = (line[0].f+line[1].f)/2,midy=(line[0].s+line[1].s)/2;
    vector<pd> line1=line,line2=line;

    line1[1]=make_pair(midx,midy);

    line2[0]= make_pair(midx, midy);
    if( abs(midx -line[1].f)>1 && abs(midy - line[1].s)>1) //if line2!=current line
        mid_point_clip(line2);
    if(abs(midx -line[1].f)>1 && abs(midy - line[1].s)>1) //if line1!=current line
        mid_point_clip(line1);
}
void midPoint(void)
{
    for(int i=0;i<ar.size();i++)
        mid_point_clip(ar[i]);
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

void midPoint_subdivision()
{
             drawlines();
             draw_rect(0);
             midPoint();    /// these function also needed: bit_cal() clipable() mid_point_clip()
             draw_rect(2000);
}
void DisplayFunction(void)
{
	    ///Uncomment any function to run
	    //cohen_sutherland();
        midPoint_subdivision();
        //liang_barsky();
        //sutherland_hodg();
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
*/
