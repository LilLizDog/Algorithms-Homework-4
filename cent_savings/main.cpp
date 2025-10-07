#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main() {
    // read n items and d dividers
    int n, d;
    std::cin >> n >> d;

    std::vector<long long> price(n+1);
    // read prices
    for (int i = 1; i <= n; i++) {
        // item amount
        std::cin >> price[i];
    }

    // price sum over all items
    std::vector<long long> PS(n+1);
    PS[0] = 0;
    // go through each item price
    for (int i = 1; i <= n; i++) {
            // add the last price to the current prices
            PS[i] = PS[i-1] + price[i];
        }

    const long long INF = 1e15;
    std::vector<long long> prev(n+1,INF);
    std::vector<long long> current(n+1, INF);
    
    // base layer
    prev[0] = 0;
    for (int i = 0; i <= n;i++) {
        int x = PS[i] - PS[0];
        prev[i] = 10 * ((x+5) / 10);
    }

    long long bestOverall = prev[n];

    for (int g = 2; g <= d +1; g++) {
        // reset current layer 
        for (int i = 0; i <= n; i++) {
            current[i] = INF;
        }

        for (int i = g; i <= n; i++) {
            long long best = INF;
            for (int t = g-1; t < i; t++) {
                if (prev[t] == INF) 
                    continue;
                long long candidate = prev[t] + (10 * (((PS[i] - PS[t]) + 5) / 10));
                if (candidate < best) 
                    best = candidate;
            }
            current[i] = best;
        }
        // move to next layer
        prev.swap(current);
        
        // update global best 
        bestOverall = std::min(bestOverall, prev[n]);
    }
    
    std::cout << bestOverall << '\n';
    return 0;
}
