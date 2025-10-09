#include <iostream>
#include <vector>

/*
This is prefix sum, or round(sum(arr[k+1:i+1])) + opt(k,d-1)
Or what is the minimum number of coins to pay for first i items with d dividers?
*/

inline long long round(long long cents)
{
    return 10 * ((cents + 5) / 10);
}

int main()
{
    int N, D;
    std::cin >> N >> D;

    std::vector<long long> items(N), ps(N);
    long long sum = 0;
    for (auto i = 0; i < N; ++i)
    {
        long long item;
        std::cin >> item;
        items[i] = item;
        sum += item;
        ps[i] = sum;
    }

    std::vector<long long> dp1(N), dp2(N);
    for (auto i = 0; i < N; ++i)
    {
        dp1[i] = round(ps[i]);
    }
    for (auto d = 1; d <= D; ++d)
    {
        for (auto i = 0; i < N; ++i)
        {
            long long min = 1e15;
            for (auto k = 0; k <= i; ++k)
            {
                auto val = dp1[k] + round(ps[i] - ps[k]);
                min = std::min(min, val);
            }
            dp2[i] = min;
        }
        std::swap(dp1, dp2);
    }
    std::cout << dp1[N - 1] << std::endl;
}