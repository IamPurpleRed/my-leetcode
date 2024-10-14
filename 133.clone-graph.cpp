/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
  public:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& um) {
        Node* clone = new Node(node->val);
        um[node] = clone;
        vector<Node*> clone_neighbors;
        for (Node* neighbor : node->neighbors) {
            if (um.count(neighbor)) clone_neighbors.push_back(um[neighbor]);
            else clone_neighbors.push_back(dfs(neighbor, um));
        }
        clone->neighbors = clone_neighbors;

        return clone;
    }

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> um;
        return dfs(node, um);
    }
};
// @lc code=end
