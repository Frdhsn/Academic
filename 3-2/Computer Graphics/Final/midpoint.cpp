#include<bits/stdc++.h>

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


void mid_point_clip(vector<pd> line)
{
    pbb a=bit_cal(line[0].f,line[0].s);
    pbb b=bit_cal(line[1].f,line[1].s);
    int clip=clipable(a,b);
    if(clip==0)
    {
        cout<<"inside\n";
        return;
    }
    else if(clip==-1)
         {cout<<"outside\n";return;}
    cout<<"Previous point: (x1,y1) = ("<<line[0].f<<","<<line[0].s<<"); (x2,y2) and ("<<line[1].f<<" "<<line[1].s<<")"<<endl;
    double midx = (line[0].f+line[1].f)/2,midy=(line[0].s+line[1].s)/2;
    vector<pd> line1=line,line2=line;
    cout<<midx<<" "<<midy<<endl;
    line1[1]=make_pair(midx,midy);

    line2[0]= make_pair(midx, midy);
    if( abs(midx -line[1].f)>.1 && abs(midy - line[1].s)>.1) //if line2!=current line
        mid_point_clip(line2);
    if(abs(midx -line[1].f)>.1 && abs(midy - line[1].s)>.1) //if line1!=current line
        mid_point_clip(line1);
}
void midPoint(void)
{
    for(int i=0;i<v.size();i++)
        {
            cout<<"point no"<<i<<endl;
            mid_point_clip(v[i]);}
}
int main()
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
    midPoint();
    cout<<endl;
    for(i=0; ans.size(); i++)
    {
        for(j=0;j<ans[i].size();j++)
            {cout<<ans[i][j].f<<" "<<ans[i][j].s<<" : ";
            cout<<bit[i][j].b1<<" "<<bit[i][j].b2<<" "<<bit[i][j].b3<<" "<<bit[i][j].b4<<"\n";
            }
            cout<<endl;
    }
    return 0;
}
/*
-3 1 2 6
3
2
-4 2
-1 7
2
1 2
-2 3
2
-4 7
-2 10
*/
