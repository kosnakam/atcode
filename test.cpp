#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main()
{
    int n, x;
    std::cin >> n >> x;
    std::vector<int> m;
    for (int i=0; i < n; i++)
    {
        int x;
        std::cin >> x;
        m.push_back(x);
    }
    x -= std::accumulate(m.begin(), m.end(), 0);
    auto it = std::min_element(m.begin(), m.end());
    std::cout << n + x / *it;
    return (0);
}
