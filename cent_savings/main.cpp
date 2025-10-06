#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    int d;
    int n;
    std::cin >> N;
    std::cin >> d;
    std:: cin >> n
    std::vectort<long long> prices(n+1);
    
    // go through each item
    for (int i = 0; i < N; i++) {
        // item amount
        std::cin >> price[i];

        // price sum over all items
        std::vector<long long> PS(n+1);
        PS[0] = 0;
        
        // go through each item price
        for (int j = 1; j < n+1; i++) {
            // add the last price to the current prices
            int x = PS[j-1] + PS[j];
            // round item prices
            PS[i] = 10 * ((x + 5) / 10);
            // need to insert into prices?
            prices.insert(PS[i]);
        }

        // BASE CASE
        //std::vector<std::vector<long long>> DP(n+1,)
    }
}
