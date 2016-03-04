class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == NULL)
            return head;
        ListNode *p = head;
        for (int i = 1; i <= k-1 && p != NULL; i++)
            p = p->next;
        if (p == NULL)
            return head;
        p = head;
        ListNode *q = head->next;
        for (int i = 1; i <= k - 1 && q != NULL; i++){
            ListNode *tmp = q->next;
            q->next = p;
            p = q;
            q = tmp;
        }
        head->next = reverseKGroup(q, k);
        return p;
    }
};
