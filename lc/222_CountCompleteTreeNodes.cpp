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
    int getLeftDep(TreeNode *root){
        if (root == NULL)   return 0;
        return getLeftDep(root->left) + 1;
    }
    int getRightDep(TreeNode *root){
        if (root == NULL)   return 0;
        return getRightDep(root->right) + 1;
    }
    int countNodes(TreeNode* root) {
        int l = getLeftDep(root);
        int r = getRightDep(root);
        if (l == r){
            return (1 << l) - 1;
        } else{
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
};