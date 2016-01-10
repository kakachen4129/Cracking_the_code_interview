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
    int checkBalance(TreeNode *root, bool &ret){
        if (root == nullptr)    return 0;
        int l = checkBalance(root->left, ret);
        int r = checkBalance(root->right, ret);
        if (abs(l-r) >= 2)   ret = false;
        return max(l, r)+1;
    }
    bool isBalanced(TreeNode* root) {
        bool ret = true;
        checkBalance(root, ret);
        return ret;
    }
};