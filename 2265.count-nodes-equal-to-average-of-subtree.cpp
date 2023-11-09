/*
 * @lc app=leetcode id=2265 lang=cpp
 *
 * [2265] Count Nodes Equal to Average of Subtree
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
    int cnt = 0;
    pair<int, int> fun(TreeNode* node) {
        pair<int, int> p(0, 0);
        if (!node) return p;
        pair<int, int> left = fun(node->left), right = fun(node->right);
        if (left.first == 0 && right.first == 0) {
            cnt++;
            p.first++;
            p.second = node->val;
        } else {
            p.first = left.first + right.first + 1;
            p.second = left.second + right.second + node->val;
            if (p.second / p.first == node->val) cnt++;
        }

        return p;
    }
    int averageOfSubtree(TreeNode* root) {
        fun(root);
        return cnt;
    }
};
// @lc code=end
