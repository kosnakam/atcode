#include <bits/stdc++.h>
using namespace std;
#define rep(n) for (int i=0; i < n; ++i)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int w, h, n;
    cin >> w >> h >> n;
    int x_min = 0, x_max = w;
    int y_min = 0, y_max = h;

    rep(n)
    {
        int x, y, a;
        cin >> x >> y >> a;
        if (a == 1) x_min = max(x_min, x);
        else if (a == 2) x_max = min(x_max, x);
        else if (a == 3) y_min = max(y_min, y);
        else if (a == 4) y_max = min(y_max, y);
    }
    int width = max(0, x_max - x_min);
    int height = max(0, y_max - y_min);
    cout << width * height << endl;
    return 0;
}
