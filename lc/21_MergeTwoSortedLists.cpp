class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode *p = &dummy;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        while (p1 != NULL && p2 != NULL){
            if (p1->val < p2->val){
                p->next = p1;
                p = p->next;
                p1 = p1->next;
            }
            else{
                p->next = p2;
                p = p->next;
                p2 = p2->next;
            }
        }
        if (p1 == NULL)
            p->next = p2;
        else
            p->next = p1;
        return dummy.next;        
    }
};
