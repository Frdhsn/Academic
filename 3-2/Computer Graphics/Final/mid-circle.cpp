#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x, y, r, i;
    cout << "Enter radius r: " << endl;
    cin >> r;
    x = 0; y = r;
    vector<int> vx, vy;
    int di = 1 - r;
    cout << "|x\ty\tdi+1|" << endl;
    cout << "|" << x << "\t" << y << "\t" << di << "|" << endl;
    vx.push_back(x); vy.push_back(y);
    while (x <= y)
    {


        if (di < 0)
            di = di + 2 * x + 3;
        else {
            di = di + 2 * x - 2 * y + 10;
            y--;
        }
        x++;
        cout << "|" << x << "\t" << y << "\t" << di << "|" << endl;
        vx.push_back(x); vy.push_back(y);

    }
    for (i = vx.size() - 1; i >= 0; i--)
    {
        cout << "|" << vy[i] << "\t" << vx[i] << "\t|" << endl;
    }

    return 0;
}
