class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max = INT_MIN;

        for (int i = 0; i < heights.size(); i++) {
            int cur = heights[i];
            if (i + 1 < heights.size() && cur == heights[i + 1]) continue;

            int w = 1;
            
            for (int j = i + 1; j < heights.size(); j++) {
                if (heights[j] < cur) break;
                w += 1;
            }

            for (int j = i - 1; j >= 0; j--) {
                if (heights[j] < cur) break;
                w += 1;
            }

            int r = cur * w;
            if (r > max) max = r;
        }

        return max;
    }
};