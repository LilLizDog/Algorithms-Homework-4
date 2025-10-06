#include <iostream>
#include <unordered_map>
#include <vector>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> trains(N);
    for (auto &t : trains)
        std::cin >> t;

    std::vector<int> nondec(N);
    for (int i = N - 1; i >= 0; --i)
    {
        const int &t = trains[i];
        int max = 0;
        for (int j = i + 1; j < N; ++j)
        {
            if (t > trains[j])
            {
                max = std::max(nondec[j], max);
            }
        }
        nondec[i] = max + 1;
    }

    std::vector<int> noninc(N);
    for (int i = N - 1; i >= 0; --i)
    {
        const int &t = trains[i];
        int max = 0;
        for (int j = i + 1; j < N; ++j)
        {
            if (t < trains[j])
            {
                max = std::max(noninc[j], max);
            }
        }
        noninc[i] = max + 1;
    }

    int max = 0;
    for (int i = 0; i < N; ++i)
    {
        auto sum = nondec[i] + noninc[i];
        max = std::max(sum, max);
    }

    std::cout << std::max(0, max - 1) << std::endl;
}