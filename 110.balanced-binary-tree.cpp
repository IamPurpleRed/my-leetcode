/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    bool isBalanced(TreeNode* root) {
        return (depth(root) != -1) ? true : false;
    }

    int depth(TreeNode* node) {  // 這個點是最後第幾層
        if (node == nullptr) return 0;
        int left = depth(node->left);
        int right = depth(node->right);
        if (left == -1 || right == -1 || abs(left - right) > 1)
            return -1;  // 回傳 -1 代表不是平衡樹，無條件往上傳
        else return max(left, right) + 1;
    }
};
// @lc code=end
