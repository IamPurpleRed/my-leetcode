/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int level_sum = 1;
        while (!q.empty()) {
            int next_level_sum = level_sum << 1;
            vector<int> level_nodes;
            for (int i = 0; i < level_sum; i++) {
                TreeNode* node = q.front();
                q.pop();
                level_nodes.push_back(node->val);
                if (node->left) q.push(node->left);
                else next_level_sum--;
                if (node->right) q.push(node->right);
                else next_level_sum--;
            }
            ans.push_back(level_nodes);
            level_sum = next_level_sum;
        }

        return ans;
    }
};
// @lc code=end
