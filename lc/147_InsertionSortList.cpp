/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode insertionSortList(ListNode head) {
        ListNode header = new ListNode(-1);
        header.next = null;
        ListNode p = head;
        while (p != null){
            ListNode tmp = p.next;
            insertNode(header, p);
            p = tmp;
        }
        return header.next;
    }
    
    private void insertNode(ListNode header, ListNode t){
        ListNode p = header;
        ListNode q = header.next;
        while (q != null && t.val > q.val){
            p = p.next;
            q = q.next;
        }
        p.next = t;
        t.next = q;
    }
}