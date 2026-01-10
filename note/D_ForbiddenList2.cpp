#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, q;
    if (!(std::cin >> n >> q)) return 0;

    std::vector<long> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::sort(a.begin(), a.end());

    for (int i = 0; i < q; i++)
    {
        long x, k;
        std::cin >> x >> k;

        long low = x + k - 1;
        long high = x + k + n;
        long ret = high;
        auto it = std::lower_bound(a.begin(), a.end(), x);
        long index = std::distance(a.begin(), it);

        while (low <= high)
        {
            long mid = low + (high - low) / 2;
            auto iter = std::upper_bound(a.begin(), a.end(), mid);
            long ind = std::distance(a.begin(), iter);
            long in_a = ind - index;
            long total = mid - x + 1;
            long missing = total - in_a;
            if (missing >= k)
            {
                high = mid - 1;
                ret = mid;
            }
            else
                low = mid + 1;
        }
        std::cout << ret << std::endl;
    }
    return (0);
}
