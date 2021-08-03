#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a, b, dx, dy, di, x, y;
    cin >> a >> b;
// dx,dy initial
    dx = 0;
    dy = 2 * a * a * b;
    di = b * b - a * a * b + 0.25 * a * a;
    x = 0;
    y = b;
    cout << "|dx\tdy  \tdi  \tx\ty|" << endl;

    cout << "|" << dx << "\t" << dy << "  \t" << di << "  \t" << x << "\t" << y << "|" << endl;


    while (dx < dy)
    {

        x++;
        dx += 2 * b * b;
        if (di < 0)
            di = di + dx + b * b;
        else
        {
            y--;
            dy = dy - 2 * a * a;
            di = di + dx + b * b - dy;
        }
        if (dx < dy)
            cout << "|" << dx << "\t" << dy << "  \t" << di << "  \t" << x << "\t" << y << "|" << endl;
    }
    cout << "\n\nRegion2\n\n";

    di = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b;
    cout << "|dx\tdy\t  di  \t x\ty|" << endl;
    cout << "|" << dx << "\t" << dy << "  \t" << di << "  \t" << x << "\t" << y << "|" << endl;


    while (y >= 0)
    {
        y--;
        dy -= 2 * a * a;
        if (di >= 0)
            di = di + a * a - dy;
        else
        {
            x++;
            dx += 2 * b * b;
            di = di + dx + a * a - dy;
        }
        if (y >= 0)
            cout << "|" << dx << "\t" << dy << "\t  " << di << "\t  " << x << "\t" << y << "|" << endl;
    }
    return 0;
}
