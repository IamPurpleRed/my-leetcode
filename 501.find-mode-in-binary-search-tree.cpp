/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  public:
    vector<int> findMode(TreeNode *root) {
        map<int, int> m;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode *node = s.top();
            int val = node->val;
            s.pop();
            m[val] = (m.count(val)) ? m[val] + 1 : 1;
            if (node->left) s.push(node->left);
            if (node->right) s.push(node->right);
        }

        vector<int> ans;
        int record = 0;
        for (auto cnt : m) {
            if (cnt.second > record) {
                record = cnt.second;
                ans.clear();
                ans.push_back(cnt.first);
            } else if (cnt.second == record) {
                ans.push_back(cnt.first);
            }
        }

        return ans;
    }
};
// @lc code=end
