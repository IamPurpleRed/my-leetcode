/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root) return ret;
        if (root->left) {
            vector<int> l = inorderTraversal(root->left);
            ret.insert(ret.end(), l.begin(), l.end());
        }
        ret.push_back(root->val);
        if (root->right) {
            vector<int> r = inorderTraversal(root->right);
            ret.insert(ret.end(), r.begin(), r.end());
        }

        return ret;
    }
};
// @lc code=end
