//#include<bits/stdc++.h>
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

#define pb push_back

struct point{ // structure of a point
    double x,y;
    point(double a,double b){
        x = a;
        y = b;
    }
};
void printpoint(point p){ // utility function to print a point
    cout<<"("<<p.x<<","<<p.y<<")"<<endl;
}
point intersection(point p1,point q1,point p2,point q2){ // returns intersection point of two straight lines.
    double x = (p1.x*q1.y - p1.y*q1.x) * (p2.x-q2.x) - (p1.x-q1.x) * (p2.x*q2.y - p2.y*q2.x);
    x/= ((p1.x-q1.x) * (p2.y-q2.y) - (p1.y-q1.y) * (p2.x-q2.x));
    double y = (p1.x*q1.y - p1.y*q1.x) * (p2.y-q2.y) - (p1.y-q1.y) * (p2.x*q2.y - p2.y*q2.x);
    y/= ((p1.x-q1.x) * (p2.y-q2.y) - (p1.y-q1.y) * (p2.x-q2.x));
    point res(x,y);
    return res;
}
double det(point p1,point p2,point x){ // utility function which determines if a point is on the right side of a line
    double res = (p2.x-p1.x) * (x.y-p1.y) - (p2.y-p1.y) * (x.x-p1.x);
    return res;
}
vector<point> clip(vector<point>polygon,point p1,point p2){ // function to clip polygon with respect to an edge of the clipper window
    vector<point>temp;

    for(int i=0;i<polygon.size();i++){
        int j = (i+1)%polygon.size();

        point X(polygon[i].x,polygon[i].y);
        point Y(polygon[j].x,polygon[j].y);

        int det1 = det(p1,p2,X);
        int det2 = det(p1,p2,Y);


        if(det1<0 && det2<0){ // when both points are inside
            // second point is pushed
            temp.pb(Y);
        }
        else if(det1<0&&det2>=0){ // second point is outside
            // intersection point is pushed
            temp.pb(intersection(p1,p2,X,Y));
        }
        else if(det1>=0&&det2<0){ // first point is outside
            // intersection point and second points are pushed
            temp.pb(intersection(p1,p2,X,Y));
            temp.pb(Y);
        }
    }
    return temp;
}
void sutherland_hodg(vector<point>polygon,vector<point>clipper,int clipper_sz){ // function that applies sutherland-hodg algorithm
    for(int i=0;i<clipper_sz;i++){
        int j = (i+1)%clipper_sz;
        point point1(clipper[i].x,clipper[i].y);
        point point2(clipper[j].x,clipper[j].y);
        polygon = clip(polygon,point1,point2); // after clipping the polygon , clipped polygon is our next subject polygon

    }
    for(int j=0;j<polygon.size();j++){
        printpoint(polygon[j]);
    }
}
int main(){

    int clipper_sz,polygon_sz;
    cout<<"Enter the number of sides of the clipper: ";
    cin>>clipper_sz;
    vector<point>clipper;
    for(int i=0;i<clipper_sz;i++){
        point p(0,0);
        cin>>p.x>>p.y;
        clipper.pb(p);
    }
    cout<<"Enter the number of sides of the polygon: ";
    cin>>polygon_sz;
    vector<point>polygon;
    for(int i=0;i<polygon_sz;i++){
        point p(0,0);
        cin>>p.x>>p.y;
        polygon.pb(p);
    }
    sutherland_hodg(polygon,clipper,clipper_sz);
    return 0;
}
/*
4
150 150
150 200
200 200
200 150
3
100 150
200 250
300 200

3
100.0 300.0
300.0 300.0
200.0 100.0
3
100.0 150.0
200.0 250.0
300.0 200.0
*/
