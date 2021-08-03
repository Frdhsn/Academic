#include<bits/stdc++.h>
#include <stdio.h>
#include <GL/glut.h>
#include <windows.h>
#include <mmsystem.h>


#define b1 first.first
#define b2 first.second
#define b3 second.first
#define b4 second.second
#define s second
#define f first
#define pbk push_back

using namespace std;
typedef long long int ll;
typedef pair<double,double> pd;   //pd is similar to points
typedef pair<bool,bool> pb;
typedef pair<pb,pb> pbb;
const int mx=1e6;


double xmin,xmax,ymin,ymax;
vector<vector<pd>> v,ans;
vector<pd> neew;
vector<vector<pbb>> bit;

pbb bit_cal(int x,int y)
{
     pbb tmp;
     tmp.b1=0;tmp.b2=0;tmp.b3=0;tmp.b4=0;
        if(y>ymax)
            tmp.b1=1;
        if(y<ymin)
            tmp.b2=1;
        if(x>xmax)
            tmp.b3=1;
        if(x<xmin)
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
for(i=0;i<v.size();i++)
{
    vector<pbb> bit2;
    for(j=0;j<v[i].size();j++)
    {
        pbb tmp;
        tmp=bit_cal(v[i][j].f,v[i][j].s);
        bit2.pbk(tmp);
    }
    bit.pbk(bit2);
}

}
void cohen(void)
{
    bit_init();
    int i,j;
    for(i=0;i<v.size();i++)
    {
        if(clipable(i)==0)
            ans.push_back(v[i]);
        else if(clipable(i)==1)
        {
            double y1=v[i][0].s,y2=v[i][1].s;
            double x1=v[i][0].f,x2=v[i][1].f;
            double dy=y1-y2,dx=x1-x2;
            double m=dy/dx;
            double c=y1-m*x1;
            for(j=0;j<v[i].size();j++)
            {
                int f=0;
                if(bit[i][j].b1)
                   {v[i][j].s=ymax;f=1;}
                if(bit[i][j].b2)
                    {v[i][j].s=ymin;f=1;}
                if(f==1&&dy!=0&&dx!=0)
                    v[i][j].f=(v[i][j].s-c)/m;
                else{
                if(bit[i][j].b3)
                    {v[i][j].f=xmax;f=2;}
                if(bit[i][j].b4)
                   {v[i][j].f=xmin;f=2;}
                if(f==2&&dy!=0&&dx!=0)
                    v[i][j].s=m*v[i][j].f+c;}


            }
            ans.push_back(v[i]);
        }
    }
}

void liang(void){

    int i,j;
    for(i=0;i<v.size();i++)
    {

            double y1=v[i][0].s,y2=v[i][1].s;
            double x1=v[i][0].f,x2=v[i][1].f;
            double dy=y2-y1,dx=x2-x1;
            double p[4]={-1*dx,dx,-1*dy,dy},r[4],u1=0,u2=1;
            double q[4]={x1-xmin,xmax-x1,y1-ymin,ymax-y1};
             bool f=0;
            for(j=0;j<4;j++)
             {
                 //cout<<p[j]<<" "<<q[j]<<endl;
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
                 v[i][0].f=x1+dx*u1;
                 v[i][0].s=y1+dy*u1;
                 v[i][1].f=x1+dx*u2;
                 v[i][1].s=y1+dy*u2;
                 ans.push_back(v[i]);
             }
        }
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
	glColor3ub(255, 112, 148);
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
    for(int i=0;i<v.size();i++)
        mid_point_clip(v[i]);
}

typedef enum
{
    Top,Bottom, Left, Right
} side;


bool get_stat(pd p , side e)
{
    if(e==Left&& p.f < xmin)
            return 0;
   else if(e==Right&& p.f > xmax)
            return 0;
   else if(e==Top&& p.s > ymax)
            return 0;
   else if(e==Bottom&& p.s < ymin)
            return 0;
    return 1;
}

pd Intersect(vector<pd> line, side e)
{
    double x,y;

    switch(e)
    {
    case Left :
        y = line[0].s + ((line[1].s-line[0].s)*(xmin-line[0].f))/(line[1].f-line[0].f);
        x = xmin;
        break;
    case Right :
        y = line[0].s + ((line[1].s-line[0].s)*(xmax-line[0].f))/(line[1].f-line[0].f);
        x = xmax;
        break;
    case Top :
        x = line[0].f + ((line[1].f-line[0].f)*(ymax-line[0].s))/(line[1].s - line[0].s);
        y = ymax;
        break;
    case Bottom :
        x = line[0].f + ((line[1].f-line[0].f)*(ymin-line[0].s))/(line[1].s - line[0].s);
        y = ymin;
        break;
    }
    return make_pair(x,y);
}
void suther(void)
{
      ans=v;
    for (int e=0;e<2;e++)  //1 edge
    {
                            // only oneside works at a time
                            //because of while calculating line there create devided by zero

        side ee=(side)e;
        int j,k=0;
        vector<pd> tmp;

        for(j=0;j<=ans[k].size();j++)
        {
            pd p1=ans[k][j];
            pd p2=ans[k][(j+1)%v[k].size()];
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
       // neew.clear();
        //cout<<tmp.size()<<endl;
        ans[k].clear();
        ans[k]=tmp;

        //cout<<e<<endl;
    }

}

void weiler (void)
{

}

void draw_poly(int x)
{
    glBegin(GL_POLYGON);
	glColor3ub(255, 112, 148);
	for(int j=0;j<v[0].size();j++)
	glVertex2d(v[0][j].f+x,v[0][j].s);
	glEnd();
}
void draw_polyans(int x)
{
    glBegin(GL_POLYGON);
	glColor3ub(255, 112, 148);
	for(int j=0;j<ans[0].size();j++)
	glVertex2d(ans[0][j].f+x,ans[0][j].s);
	glEnd();
}
void draw_rect(int x)
{
    glBegin(GL_LINE_STRIP);
    glColor3ub(100,250,100);
    glVertex2d(xmin+x,ymin);
    glVertex2d(xmin+x,ymax);
    glVertex2d(xmax+x,ymax);
    glVertex2d(xmax+x,ymin);
    glVertex2d(xmin+x,ymin);
    glEnd();
}
void drawlines()
{
    for(int i =0;i<v.size();i++)
    {
    glBegin(GL_LINE_STRIP);
	glColor3ub(255, 112, 148);
	glVertex2d(v[i][0].f,v[i][0].s);
	glVertex2d(v[i][1].f,v[i][1].s);
	glEnd();
	}
}
void drawline_ans(int x)
{
    for(int i =0;i<ans.size();i++)
    {
    glBegin(GL_LINE_STRIP);
	glColor3ub(255, 112, 148);
	glVertex2d(ans[i][0].f+x,ans[i][0].s);
	glVertex2d(ans[i][1].f+x,ans[i][1].s);
	glEnd();
	}
}

void liang_barsky(){

             drawlines();
             draw_rect(0);
             liang();
             drawline_ans(1500);
             draw_rect(1500);
}
void cohen_sutherland(){

             drawlines();
             draw_rect(0);
             cohen();   /// these function also needed: bit_cal() bit_init() clipable()
             drawline_ans(1500);
             draw_rect(1500);
}
void midPoint_subdivision()
{
             drawlines();
             draw_rect(0);
             midPoint();    /// these function also needed: bit_cal() clipable() mid_point_clip()
             draw_rect(1500);
}
void sutherland_hodg()
{
             draw_poly(0);
             draw_rect(0);
             suther();  ///these function also needed: get_stat() , Intersect()
             //cout<<v[0].size()<<endl;
             draw_polyans(1500);
             draw_rect(1500);
}


void myDisplay(void)
	{
	    ///Uncomment any function to run
	   // cohen_sutherland();
        //midPoint_subdivision();
        liang_barsky();
        // sutherland_hodg();
			 glFlush();
			 glutPostRedisplay();
			 glutSwapBuffers();
}
///ortho2d= window dimension
void sabbirInit(void)
{
	glClearColor(.1, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(200, 240, 255);
	glPointSize(0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-200.0, 4000.0, -1000.0, 2000.0);
}
int main(int argc, char** argv)
{
    int i,j,n,l;

    cout<<"Enter clip window xmin ymin xmax ymax\n"; ///"change it"
    cin>>xmin>>ymin>>xmax>>ymax;

    cout<<"Enter number of shape\n";///"change it"
    cin>>n;

    for (i=0; i<n; i++)
    {
        cout<<"enter number of vertex and them n x y\n";
        cin>>l;
        pd point;
        vector<pd> shape;
        for(j=0;j<l;j++)
        {cin>>point.f>>point.s;
        shape.pbk(point);}
        v.pbk(shape);
    }
    neew=v[0];
    ///Answer print If needed
   /* for(i=0; ans.size(); i++)
    {
        for(j=0;j<ans[i].size();j++)
            {cout<<ans[i][j].f<<" "<<ans[i][j].s<<" : ";
            //cout<<bit[i][j].b1<<" "<<bit[i][j].b2<<" "<<bit[i][j].b3<<" "<<bit[i][j].b4<<" : ";
            }
            cout<<endl;
    }*/
  	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(2000, 2000);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("Clipping");
	glutDisplayFunc(myDisplay);
	sabbirInit();
	glutMainLoop();
   // return 0;
}
/*
Cohen-suther_land
mid point
100 100 700 700
3
2
300 200
300 1000
2
200 300
800 400
2
-100 700
1100 100
2
0 0
1100 600
2
500 400
1200 400

liang
100 200 900 800
6
2
300 200
300 1000
2
200 300
500 500
2
800 900
200 1000
2
-100 700
1100 100
2
0 0
1100 600
2
500 400
1200 400


polygon worst case
100 200 900 800
1
4
-100 700
300 1000
1100 600
1100 100

polygon best case
100 200 900 800
1
4
300 1000
700 1000
200 0
600 0

*/
