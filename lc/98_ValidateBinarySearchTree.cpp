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
    void isValid(bool &ret, TreeNode* &pre, TreeNode* cur){
        if (cur == nullptr) return;
        isValid(ret, pre, cur->left);
        if (pre != nullptr && pre->val >= cur->val)
            ret = false;
        pre = cur;
        isValid(ret, pre, cur->right);
    }
    bool isValidBST(TreeNode* root) {
        bool ret = true;
        TreeNode *pre = nullptr;
        TreeNode *cur = root;
        isValid(ret, pre, cur);
        return ret;
    }
};