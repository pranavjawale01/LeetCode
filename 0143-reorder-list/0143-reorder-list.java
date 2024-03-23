/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverse(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode last = reverse(head.next);
        head.next.next = head;
        head.next = null;
        return last;
    }
    public void reorderList(ListNode head) {
        if (head == null || head.next == null) {
            return;
        }
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode rev = reverse(slow);
        ListNode curr = head;
        while (rev.next != null) {
            ListNode tempcurr = curr.next;
            curr.next = rev;

            ListNode temprev = rev.next;
            rev.next = tempcurr;

            curr = tempcurr;
            rev  = temprev;  
        }        
    }
}

// class Solution {
//     public void reorderList(ListNode head) {
//         List<Integer> arr = new ArrayList<>();
//         ListNode temp = head;
//         while (temp != null) {
//             arr.add(temp.val);
//             temp = temp.next;
//         }
//         int n = arr.size();
//         temp = head;
//         int i = 0;
//         while (temp != null && temp.next != null) {
//             temp.val = arr.get(i);
//             temp.next.val = arr.get(n - i - 1);
//             temp = temp.next.next;
//             i++;
//         }
//         if (n % 2 != 0) {
//             temp.val = arr.get(n / 2);
//         }
//     }
// }