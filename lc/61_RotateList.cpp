class Solution {
public:
ListNode *rotateRight(ListNode *head, int k) {
    int n = 0;
    if (head == NULL)   return NULL;
    ListNode *p = head;
    ListNode header(-1);
    header.next = head;
    ListNode *q = &header;
    while (p != NULL){
        q = q->next;
        p = p->next;
        n++;
    }
    q->next = head;
    k = k % n;
    p = head;
    for (int i = 1; i <= n - k - 1; i++)
        p = p->next;
    ListNode *tmp = p->next;
    p->next = NULL;
    return tmp;
}
};
