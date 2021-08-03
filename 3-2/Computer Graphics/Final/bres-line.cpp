#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x, y, x1, y1, x2, y2, dx, dy;
    cout << "Enter two end points of line (x1,y1) and (x2 y2) x1<x2 and y1<y2" << endl;
    cin >> x1 >> y1 >> x2 >> y2;
    x = x1; y = y1;
    dx = x2 - x1;
    dy = y2 - y1;
    if (dy < dx) {
        int di = 2 * dy - dx;
        cout << "|di\tx\ty|" << endl;
        cout << "|" << di << "\t" << x << "\t" << y << "|" << endl;
        while (x < x2)
        {
            x++;
            if (di < 0)
                di += 2 * dy;
            else {
                di += (2 * dy - 2 * dx);
                y++;
            }
            cout << "|" << di << "\t" << x << "\t" << y << "|" << endl;
        }
    }
    else {
        int di = 2 * dx - dy;
        cout << "|di\tx\ty|" << endl;
        cout << "|" << di << "\t" << x << "\t" << y << "|" << endl;
        while (x < x2)
        {
            y++;
            if (di < 0)
                di += 2 * dx;
            else {
                di += (2 * dx - 2 * dy);
                x++;
            }
            cout << "|" << di << "\t" << x << "\t" << y << "|" << endl;
        }


    }


    return 0;
}
