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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)   return NULL;
        ListNode header(-1);
        header.next = head;
        ListNode *p, *pre;
        pre = &header;
        p = head;
        while (p != NULL){
            if (p->val == val){
                pre->next = p->next;
                p->next = NULL;
                delete p;
                p = pre->next;
            } else{
                p = p->next;
                pre = pre->next;
            }
        }
        return header.next;
    }
};