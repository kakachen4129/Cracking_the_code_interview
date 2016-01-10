/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    // use a map to record the relations between old and new nodes
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> map;
        RandomListNode header(-1);
        RandomListNode *p1 = head;
        RandomListNode *p2 = &header;
        while (p1 != NULL){
            p2->next = new RandomListNode(p1->label);
            p2 = p2->next;
            map[p1] = p2;
            p1 = p1->next;
        }
        
        p1 = head;
        p2 = header.next;
        while (p1 != NULL){
            if (p1->random == NULL){
                p2->random = NULL;
            } else{
                p2->random = map[p1->random];
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return header.next;
    }
};