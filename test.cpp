#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    int n, d, c = 0;
    std::cin >> n >> d;
    std::vector<int> x[n];
    for (int i=0; i < n; i++)
    {
        for (int j=0; j < d; j++)
        {
            int t; std::cin >> t; x[i].push_back(t);
        }
    }


    for (int i=0; i < n - 1; i++)
    {
        for (int j=0; j < d; j++)
        {
            int ele = 0;
            for (int k=1; k + i < n; k++)
            {
                ele += pow(std::abs(x[i][j] - x[i + k][j]), 2);
            }
            std::cout << ele << std::endl;
        }
    }
    // std::cout << c;
    return (0);
}