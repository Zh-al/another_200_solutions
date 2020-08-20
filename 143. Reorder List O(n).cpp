//https://leetcode.com/problems/reorder-list/

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
    void reorderList(ListNode* head) {
        if (head == NULL) return;
        int length = countLength(head);
        vector<ListNode*> items(length);
        for (int i = 0; i < length; i += 2) {
            items[i] = head;
            head = head->next;
        }
        for (int i = length - 1 - (length % 2); i >= 1; i -= 2) {
            items[i] = head;
            head = head->next;
        }
        for (int i = 1; i < length; ++i) {
            items[i - 1]->next = items[i];
        }
        items[length - 1]->next = nullptr;
        return;
    }
    
    int countLength (ListNode* head) {
        int count = 0;
        while (head != NULL) {
            head = head->next;
            ++count;
        }
        return count;
    }
};
