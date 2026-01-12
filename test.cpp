#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for (int i=0; i < n; i++)

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, c=0;
    std::cin >> n;
    std::vector<int> l(n);
    rep(i, n) std::cin >> l[i];

    std::sort(l.begin(), l.end());
    rep(i, n - 2)
    {
        int j = i + 1;
        for (; j < n - 1; j++)
        {
            int k = j + 1;
            if (l[i] == l[j])
                continue;
            for (; k < n; k++)
            {
                if (l[k] == l[i] || l[k] == l[j])
                    continue;
                if (l[i] + l[j] > l[k])
                    c++;
            }
        }
    }
    std::cout << c;
    return (0);
}