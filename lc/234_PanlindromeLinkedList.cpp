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
    // recursion is great!!
    bool isPalindrome(ListNode* head) {
        ListNode *p = head;
        ListNode *q = head;
        isPalindromeHelper(p, q);            
    }
    bool isPalindromeHelper(ListNode* &p, ListNode *q){
        if (q == NULL)  return true;
        bool ret = isPalindromeHelper(p, q->next) && p->val == q->val;
        p = p->next;
        return ret;
    }
    
    /*bool isPalindrome(ListNode* head) {
        if (head == NULL)   return true;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        slow = head;
        fast = reverseLinkedList(fast);
        while (fast != NULL){
            if (fast->val != slow->val)
                return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
    ListNode* reverseLinkedList(ListNode *head){
        if (head == NULL)   return head;
        ListNode *p = head;
        ListNode *q = head->next;
        head->next = NULL;
        while (q != NULL){
            ListNode *tmp = q->next;
            q->next = p;
            p = q;
            q = tmp;
        }
        return p;
    }*/
};