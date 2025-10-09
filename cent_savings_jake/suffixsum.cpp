#include <iostream>
#include <vector>

/*
This is suffix sum, or round(sum(arr[i:k])) + opt(k, d-1)
Or what is the minimum number of coins to pay for arr[i:n] items with d dividers?
*/

inline long long round(long long cents)
{
    return 10 * ((cents + 5) / 10);
}

int main()
{
    int N, D;
    std::cin >> N >> D;

    std::vector<long long> items(N), ss(N);
    long long sum = 0;
    for (auto i = 0; i < N; ++i)
    {
        long long item;
        std::cin >> item;
        items[i] = item;
        sum += item;
    }
    for (auto i = 0; i < N; ++i)
    {
        ss[i] = sum;
        sum -= items[i];
    }

    std::vector<long long> dp1(N), dp2(N);
    for (auto i = 0; i < N; ++i)
    {
        dp1[i] = round(ss[i]);
    }
    for (auto d = 1; d <= D; ++d)
    {
        for (auto i = 0; i < N; ++i)
        {
            long long min = 1e15;
            for (auto k = i; k < N; ++k)
            {
                auto val = dp1[k] + round(ss[i] - ss[k]);
                min = std::min(min, val);
            }
            dp2[i] = min;
        }
        std::swap(dp1, dp2);
    }
    std::cout << dp1[0] << std::endl;
}