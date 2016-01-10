/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
ListNode* sortList(ListNode* head) {
    if (head == nullptr)    return head;
    ListNode *pivot = head;
    ListNode *eq = head;
    head = head->next;
    pivot->next = nullptr;
    ListNode small(0);
    ListNode *p1 = &small;
    ListNode great(0);
    ListNode *p2 = &great;
    ListNode *p = head;
    while (p != nullptr){
        if (p->val < pivot->val){
            p1->next = p;
            p1 = p1->next;
            p = p->next;
            p1->next = nullptr;
        } else if (p->val == pivot->val){
            eq->next = p;
            eq = eq->next;
            p = p->next;
            eq->next = nullptr;
        }
        else{
            p2->next = p;
            p2 = p2->next;
            p = p->next;
            p2->next = nullptr;
        }
    }
    ListNode *head1 = sortList(small.next);
    ListNode *head2 = sortList(great.next);
    eq->next = head2;
    if (head1 == nullptr)   return pivot;
    else{
        p = head1;
        while (p->next != nullptr)
            p = p->next;
        p->next = pivot;
    }
    return head1;
}
};