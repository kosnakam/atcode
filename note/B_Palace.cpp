// https://atcoder.jp/contests/abc113/tasks/abc113_b

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
    int n, t, a;
    std::cin >> n >> t >> a;
    std::vector<int> h;
    for (int i=0; i < n; i++)
    {
        int tmp;
        std::cin >> tmp;
        h.push_back(tmp);
    }

    float com = (t - a) / 0.006;
    int ret;
    
    // Liner search with using the lambda function. (O(N))
    auto it = std::min_element(h.begin(), h.end(), 
        [com](int a, int b)
        {
            return std::abs(a - com) < std::abs(b - com);
        });
    ret = std::distance(h.begin(), it);

    // lower_bound (O(logN)) but i use sort (O(NlogN))
    // auto tmp = h;
    // int val;
    // std::sort(h.begin(), h.end());
    // auto it = std::lower_bound(h.begin(), h.end(), com);
    // if (it != h.begin() && it != h.end())
    // {
    //     if (std::abs(com - *(it - 1)) < std::abs(com - *it))
    //         val = *(it - 1);
    // }
    // else
    //     val = *it;
    // auto iter = std::find(tmp.begin(), tmp.end(), val);
    // ret = std::distance(tmp.begin(), iter);

    std::cout << ret + 1;
    return (0);
}
