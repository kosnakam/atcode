#include <bits/stdc++.h>
using namespace std;
#define rep(n) for (int i=0; i < n; ++i)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n;
    vector<string> s(n); rep(n) cin >> s[i];
    cin >> m;
    vector<string> t(m); rep(m) cin >> t[i];

    int ret = 0;
    for (string str: s)
    {
        int c=0;
        rep(n) if (s[i] == str) ++c;
        rep(m) if (t[i] == str) --c;
        ret = max(ret, c);
    }
    cout << ret;
    return 0;
}
