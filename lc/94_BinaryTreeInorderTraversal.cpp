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
    /*TreeNode* getNext(stack<TreeNode*> &st, TreeNode* &p){
        while (p != nullptr || st.empty() != true){
            if (p != nullptr){
                st.push(p);
                p = p->left;
            } else{
                TreeNode *tmp = st.top();
                st.pop();
                p = tmp->right;
                return tmp;
            }
        }
        return nullptr;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *p = root;
        stack<TreeNode*> st;
        vector<int> ret;
        TreeNode *cur;
        while ((cur = getNext(st, p)) != nullptr)
            ret.push_back(cur->val);
        return ret;
    }*/
    
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *p = root;
        stack<TreeNode*> st;
        vector<int> ret;
        while (p != nullptr || st.empty() != true){
            if (p != nullptr){
                st.push(p);
                p = p->left;
            } else{
                TreeNode *tmp = st.top();
                ret.push_back(tmp->val);
                st.pop();
                p = tmp->right;
            }
        }
        return ret;
    }
};