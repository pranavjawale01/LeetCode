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
    ListNode *reverse(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *last = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *rev= reverse(slow);
        ListNode *curr = head;
        while (rev->next != nullptr) {
            ListNode *tempcurr = curr->next;
            curr->next = rev;

            ListNode *temprev = rev->next;
            rev->next = tempcurr;

            curr = tempcurr;
            rev = temprev;
        }
    }
};

// class Solution {
// public:
//     void reorderList(ListNode* head) {
//         if (!head || !head->next) {
//             return;
//         }
//         ListNode *temp = head;
//         vector<int> arr;
//         while (temp) {
//             arr.push_back(temp->val);
//             temp = temp->next;
//         }
//         int n = arr.size();
//         temp = head;
//         int i = 0;
//         while (temp && temp->next) {
//             temp->val = arr[i];
//             temp->next->val  = arr[n - i - 1];
//             temp = temp->next->next;
//             i++;
//         }
//         if (n % 2 != 0) {
//             temp->val = arr[(n) / 2];
//         }
//     }
// };