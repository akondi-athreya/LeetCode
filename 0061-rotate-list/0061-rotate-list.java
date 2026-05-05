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
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0) return head;
        ListNode temp = head;
        int cnt = 0;
        while (temp != null) {
            cnt++;
            temp = temp.next;
        }
        k = k % cnt;
        if (k == 0) return head;
        temp = head;
        cnt -= k;
        while (cnt - 1 > 0) {
            temp = temp.next;
            cnt--;
        }
        ListNode newHead = temp.next;
        temp.next = null;
        ListNode ntemp = newHead;
        while (ntemp.next != null) {
            ntemp = ntemp.next;
        }
        ntemp.next = head;
        return newHead;
    }
}