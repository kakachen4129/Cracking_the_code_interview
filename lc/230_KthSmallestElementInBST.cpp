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
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int ret = 0;
        getKthSmallest(root, cnt, ret, k);
        return ret;
    }
    void getKthSmallest(TreeNode* root, int &cnt, int &ret, int k){
        if (root == NULL)   return;
        getKthSmallest(root->left, cnt, ret, k);
        cnt++;
        if (cnt == k)   ret = root->val;
        getKthSmallest(root->right, cnt, ret, k);
    }
};