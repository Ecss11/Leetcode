//
// Created by ECSS11 on 9/23/2025.
//

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = 0;
        int max = 0;

        int profit = 0;

        while (max < prices.size()) {
            for (int i = max; i < prices.size() ; i++) {
                if (prices[i] >= prices[max])
                    max = i;
            }

            for (int i = min; i < max; i++) {
                if (prices[i] <= prices[min])
                    min = i;
            }

            int diff = prices[max] - prices[min];
            if (diff > profit)
                profit = diff;

            max += 1;
        }

        return profit;
    }
};