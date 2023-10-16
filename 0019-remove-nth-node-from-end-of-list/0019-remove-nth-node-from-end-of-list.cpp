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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* result = new ListNode(0);
        result->next = head;
        ListNode* first = result;
        ListNode* second = result;
        for (int i = 1; i <= n + 1; i++) 
        {
            first = first->next;
        }
        while (first != nullptr) 
        {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return result->next;
    }
};