/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findMis(TreeNode* &pre, TreeNode *cur, TreeNode* &p1, TreeNode* &p2){
        if (cur == nullptr) return;
        findMis(pre, cur->left, p1, p2);
        if (pre != nullptr && pre->val > cur->val){
            if (p1 == nullptr && p2 == nullptr){
                p1 = pre;
                p2 = cur;
            } else{
                p2 = cur;
            }
        }
        pre = cur;
        findMis(pre, cur->right, p1, p2);
    }
    void recoverTree(TreeNode* root) {
        TreeNode *pre = nullptr;
        TreeNode *cur = root;
        TreeNode *p1 = nullptr;
        TreeNode *p2 = nullptr;
        findMis(pre, cur, p1, p2);
        swap(p1->val, p2->val);
    }
};