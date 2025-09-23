//
// Created by ECSS11 on 9/23/2025.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre = nums;
        for(int i = 1; i < n; i++)
            pre[i] += max(0, pre[i-1]);
        return *max_element(begin(pre), end(pre));
    }
};