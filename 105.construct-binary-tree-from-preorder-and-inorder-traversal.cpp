/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> um;
        for (int i = 0; i < inorder.size(); i++)
            um[inorder[i]] = i;  // 使日後尋找變成 O(1)
        int preIdx = 0;          // tree root
        return build(preorder, preIdx, um, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, int& preIdx,
                    unordered_map<int, int>& um, int start, int end) {
        // start ~ end: inorder 的尋找範圍
        if (start > end) return nullptr;

        int rootVal = preorder[preIdx];
        preIdx++;  // 等等執行的 root->left 是下一個 tree root
        TreeNode* root = new TreeNode(rootVal);
        root->left = build(preorder, preIdx, um, start, um[rootVal] - 1);
        root->right = build(preorder, preIdx, um, um[rootVal] + 1, end);

        return root;
    }
};
// @lc code=end
