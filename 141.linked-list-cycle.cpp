/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// sol 1: using hash map
class Solution {
  public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode *, bool> um;
        ListNode *current = head;
        while (current != nullptr) {
            if (um[current]) return true;
            um[current] = true;
            current = current->next;
        }

        return false;
    }
};

// sol 2: slow pointer & fast pointer
class Solution {
  public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }

        return false;
    }
};

// @lc code=end
