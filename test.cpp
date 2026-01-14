#define ll long long
#include <bits/stdc++.h>
#define rep(n) for (size_t i=0; i < n; ++i)

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    size_t n, m; std::cin >> n >> m;
    std::vector<size_t> ab(2 * m);
    rep(2 * m) std::cin >> ab[i];
    rep(n)
        std::cout << std::count(ab.begin(), ab.end(), i + 1) << std::endl;
    return (0);
}
