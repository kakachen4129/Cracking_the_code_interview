/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root){
        if (root == nullptr) return;
        TreeLinkNode header(0);
        TreeLinkNode *p = &header;
        TreeLinkNode *cur = root;
        while (cur != nullptr){
            if (cur->left != nullptr){
                p->next = cur->left;
                p = p->next;
            }
            if (cur->right != nullptr){
                p->next = cur->right;
                p = p->next;
            }
            cur = cur->next;
        }
        connect(header.next);
    }
};