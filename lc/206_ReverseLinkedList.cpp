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
    /*ListNode* reverseRecursive(ListNode* p, ListNode *q){
        if (q == NULL)  return p;
        ListNode *tmp = reverseRecursive(q, q->next);
        p->next = NULL;
        q->next = p;
        return tmp;
    }
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)   return head;
        return reverseRecursive(head, head->next);
    }*/
    
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)    return head;
        ListNode *p = head;
        ListNode *q = head->next;
        p->next = nullptr;
        while (q != nullptr){
            ListNode *tmp = q->next;
            q->next = p;
            p = q;
            q = tmp;
        }
        return p;
    }
};