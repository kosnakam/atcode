#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i < n; i++)

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int a, b, c=0; std::cin >> a >> b;

    for(;a <= b; ++a)
    {
        if (a / 10000 == a % 10 && (a / 1000) % 10 == (a % 100) / 10)
            c++;
    }
    std::cout << c;
    return (0);
}