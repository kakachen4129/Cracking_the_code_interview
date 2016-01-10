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
    void flatten(TreeNode* root) {
        if (root == NULL)   return;
        if (root->left == NULL){
            flatten(root->right);
        } else{
            TreeNode *p = root->left;
            while (p->right != NULL)
                p = p->right;
            p->right = root->right;
            root->right = root->left;
            root->left = NULL;
            flatten(root->right);
        }
    }
};