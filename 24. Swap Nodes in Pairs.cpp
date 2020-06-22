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
    ListNode* swapPairs(ListNode* head) {
        ListNode* preHead = new ListNode(0, head);
        ListNode* tempHead = preHead;
        while (tempHead != NULL && tempHead->next != NULL) {
            swapPair(tempHead);
            tempHead = tempHead->next->next;
        }
        return preHead->next;
    }
    
    void swapPair(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return;
        }
        ListNode* first = head->next;
        ListNode* second = first->next;
        head->next = second;
        first->next = second->next;
        second->next = first;
    }
};
