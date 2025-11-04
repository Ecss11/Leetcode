/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    unordered_map<int, int> counter;
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> mode;
        int max = INT_MIN;
        readVal(root);
        for (const auto& [key, val] : counter) {
            if (val < max) continue;
            if (val != max) mode.clear();

            max = val;
            mode.push_back(key);
        }
        return mode;
    }

    void readVal(TreeNode* cur) {
        if (cur == nullptr) return;
        counter[cur->val] += 1;
        readVal(cur->left);
        readVal(cur->right);
    }
};