#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    static bool isEven(const int num) {
        return num % 2 == 0;
    }

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());

        const int size = static_cast<int>(nums1.size());
        if (isEven(size)) {
            return (nums1[size / 2] + nums1[size / 2 - 1]) / 2.0;
        }

        return nums1[size / 2];
    }
};