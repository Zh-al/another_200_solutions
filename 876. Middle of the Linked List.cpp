//https://leetcode.com/problems/middle-of-the-linked-list/

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
    ListNode* middleNode(ListNode* head) {
        int length = countLength(head);
        for (int i = 0; i < length / 2; ++i, head = head->next);
        return head;
    }
    
    int countLength(ListNode* head) {
        int count = 0;
        for (count = 0; head != NULL; head = head->next, ++count);
        return count;
    }
};
