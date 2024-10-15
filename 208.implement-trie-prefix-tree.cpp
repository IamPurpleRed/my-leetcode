/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class Node {
  public:
    vector<Node*> next;
    bool isEnd;

    Node() {
        next = vector<Node*>(26, nullptr);
        isEnd = false;
    }
};

class Trie {
  public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* current = root;
        for (char c : word) {
            int idx = c - 'a';
            if (current->next[idx] == nullptr) current->next[idx] = new Node();
            current = current->next[idx];
        }
        current->isEnd = true;
    }

    bool search(string word) {
        Node* current = root;
        for (char c : word) {
            int idx = c - 'a';
            if (current->next[idx] == nullptr) return false;
            current = current->next[idx];
        }

        return current->isEnd;
    }

    bool startsWith(string prefix) {
        Node* current = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (current->next[idx] == nullptr) return false;
            current = current->next[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
