/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
  public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        else if (!list2) return list1;
        ListNode* current;
        if (list1->val < list2->val) {
            current = new ListNode(list1->val);
            list1 = list1->next;
        } else {
            current = new ListNode(list2->val);
            list2 = list2->next;
        }
        ListNode* head = current;
        while (1) {
            if (!list1) {
                current->next = list2;
                break;
            } else if (!list2) {
                current->next = list1;
                break;
            } else if (list1->val < list2->val) {
                current->next = new ListNode(list1->val);
                current = current->next;
                list1 = list1->next;
            } else {
                current->next = new ListNode(list2->val);
                current = current->next;
                list2 = list2->next;
            }
        }

        return head;
    }
};
// @lc code=end
