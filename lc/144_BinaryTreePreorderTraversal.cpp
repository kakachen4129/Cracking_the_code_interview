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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ret;
        if (root == nullptr)    return ret;
        st.push(root);
        while (st.empty() != true){
            TreeNode *tmp = st.top();
            st.pop();
            ret.push_back(tmp->val);
            if (tmp->right != nullptr)
                st.push(tmp->right);
            if (tmp->left != nullptr)
                st.push(tmp->left);
        }
        return ret;
    }
};