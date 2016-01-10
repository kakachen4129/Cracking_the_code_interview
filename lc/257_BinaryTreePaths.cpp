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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        string cur;
        getBinaryTreePaths(root, ret, cur);
        return ret;
    }
    void getBinaryTreePaths(TreeNode *p, vector<string> &ret, string cur){
        if (p == NULL)  return;
        if (p->left == NULL && p->right == NULL){
            ret.push_back(cur + to_string(p->val));
            return;
        }
        getBinaryTreePaths(p->left, ret, cur + to_string(p->val) + "->");
        getBinaryTreePaths(p->right, ret, cur + to_string(p->val) + "->");
    }
};