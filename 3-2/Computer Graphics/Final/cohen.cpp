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
    cohen();
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
