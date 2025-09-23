//
// Created by ECSS11 on 9/23/2025.
//
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> answers;

        for (int i = 0; i < size; i++) {
            answers.push_back(1);
        }

        int cur = 1;
        for (int i = 0; i < size; i++) {
            answers[i] *= cur;
            cur *= nums[i];
        }

        cur = 1;
        for (int i = size - 1; i >= 0; i--) {
            answers[i] *= cur;
            cur *= nums[i];
        }

        return answers;
    }
};