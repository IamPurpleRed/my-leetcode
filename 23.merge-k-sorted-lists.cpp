/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        else return mergeLists(lists, 0, lists.size() - 1);
    }

    ListNode* mergeLists(vector<ListNode*>& lists, int from, int to) {
        if (from > to) return nullptr;
        else if (from == to) return lists[from];
        else {
            int mid = (from + to) >> 1;
            ListNode* left = mergeLists(lists, from, mid);
            ListNode* right = mergeLists(lists, mid + 1, to);
            return mergeTwoLists(left, right);
        }
    }

    ListNode* mergeTwoLists(ListNode* ptr1, ListNode* ptr2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        while (ptr1 && ptr2) {
            if (ptr1->val < ptr2->val) {
                current->next = ptr1;
                ptr1 = ptr1->next;
            } else {
                current->next = ptr2;
                ptr2 = ptr2->next;
            }
            current = current->next;
        }
        current->next = ptr1 ? ptr1 : ptr2;

        return dummyHead->next;
    }
};
// @lc code=end
