#include <bits/stdc++.h>
using namespace std;
#define rep(n) for (int i=0; i < n; ++i)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    vector<int> a(n); rep(n) cin >> a[i];
    vector<int> kind(n, 0);
    rep(n) ++kind[a[i] - 1];
    // for (auto it = kind.begin(); it != kind.end();) if (*it == 0) it = kind.erase(it); else ++it;
    // kind.erase(remove(kind.begin(), kind.end(), 0), kind.end());
    erase(kind, 0);
    sort(kind.begin(), kind.end());
    int ret=0, in=max(0, int(kind.size()) - k);
    rep(in) ret += kind[i];
    cout << ret;
    return 0;
}
