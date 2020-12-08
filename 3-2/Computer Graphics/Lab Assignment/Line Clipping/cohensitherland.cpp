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

int clipable(int i)
{
    int sum=0,andsum=0;

        sum+=(bit[i][0].b1+bit[i][1].b1);
        andsum+=(bit[i][0].b1&bit[i][1].b1);

        sum+=(bit[i][0].b2+bit[i][1].b2);
        andsum+=(bit[i][0].b2&bit[i][1].b2);

        sum+=(bit[i][0].b3+bit[i][1].b3);
        andsum+=(bit[i][0].b3&bit[i][1].b3);

        sum+=(bit[i][0].b4+bit[i][1].b4);
        andsum+=(bit[i][0].b4&bit[i][1].b4);
    if(sum==0)
        return 0;
    else if(andsum==0)
        return 1;
    else
        return -1;
}
void bit_init(void)
{
    int i,j;
    for(i=0;i<ar.size();i++)
    {
        vector<pbb> bit2;
        for(j=0;j<ar[i].size();j++)
        {
            pbb tmp;
            tmp=bit_cal(ar[i][j].f,ar[i][j].s);
            bit2.pb(tmp);
        }
        bit.pb(bit2);
    }

}
void cohen(void)
{
    bit_init();
    int i,j;
    for(i=0;i<ar.size();i++)
    {
        if(clipable(i)==0)
            res.push_back(ar[i]);
        else if(clipable(i)==1)
        {
            double y1=ar[i][0].s,y2=ar[i][1].s;
            double x1=ar[i][0].f,x2=ar[i][1].f;
            double dy=y1-y2,dx=x1-x2;
            double m=dy/dx;
            double c=y1-m*x1;
            for(j=0;j<ar[i].size();j++)
            {
                int f=0;
                if(bit[i][j].b1)
                   {ar[i][j].s=y_maximum;f=1;}
                if(bit[i][j].b2)
                    {ar[i][j].s=y_minimum;f=1;}
                if(f==1&&dy!=0&&dx!=0)
                    ar[i][j].f=(ar[i][j].s-c)/m;
                else{
                if(bit[i][j].b3)
                    {ar[i][j].f=x_maximum;f=2;}
                if(bit[i][j].b4)
                   {ar[i][j].f=x_minimum;f=2;}
                if(f==2&&dy!=0&&dx!=0)
                    ar[i][j].s=m*ar[i][j].f+c;}


            }
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
void cohen_sutherland(){

             drawlines();
             draw_rect(0);
             cohen();
             drawline_res(2000);
             draw_rect(2000);
}
void DisplayFunction(void)
{
	    cohen_sutherland();
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

	glutCreateWindow("Clipping with cohen-sutherland algorithm");
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
