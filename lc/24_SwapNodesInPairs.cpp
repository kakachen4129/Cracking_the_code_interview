/* Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *q = head->next;
        ListNode *tmp = q->next;
        q->next = head;
        head->next = swapPairs(tmp);
        return q;
    }
};
