#include <bits/stdc++.h>
using namespace std;
#define rep(n) for (int i=0; i <= n; ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    int i = 2 * c * max(x, y);
    int j = a * x + b * y;
    int k=0;
    if (x > y)
        k = 2 * c * y + (x - y) * a;
    else
        k = 2 * c * x + (y - x) * b;
    std::cout << min({i, j, k});
    return 0;
}