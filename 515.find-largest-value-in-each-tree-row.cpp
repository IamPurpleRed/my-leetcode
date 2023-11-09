/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
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
    vector<int> largestValues(TreeNode *root) {
        vector<int> ans;
        queue<TreeNode *> q, qnext;

        if (root) {
            ans.push_back(root->val);
            if (root->left) qnext.push(root->left);
            if (root->right) qnext.push(root->right);
        }

        while (!qnext.empty()) {
            swap(q, qnext);
            int biggest = INT_MIN;
            while (!q.empty()) {
                TreeNode *node = q.front();
                q.pop();
                biggest = max(biggest, node->val);
                if (node->left) qnext.push(node->left);
                if (node->right) qnext.push(node->right);
            }
            ans.push_back(biggest);
        }

        return ans;
    }
};
// @lc code=end
