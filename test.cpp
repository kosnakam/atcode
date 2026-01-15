#define ll long long
#include <bits/stdc++.h>
using namespace std;
#define rep(n) for (ll i=1; i <= n; ++i)

int keta(ll ar)
{
    int ret=0;
    while (ar > 0)
    {
        ar /= 10;
        ++ret;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    int ret=1000000000;
    int c=sqrt(n);
    rep(c)
    {
        if (n % i == 0)
        {
            ret = min(ret, max(keta(i), keta(n / i)));
        }
    }
    cout << ret;
    return 0;
}