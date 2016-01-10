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
    TreeNode* LCA(TreeNode* p, int min, int max){
        if (p == NULL)  return p;
        if (p->val >= min && p->val <= max){
            return p;
        } else if (p->val > max){
            return LCA(p->left, min, max);
        } else{
            return LCA(p->right, min, max);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root, min(p->val, q->val), max(p->val, q->val));
    }
};