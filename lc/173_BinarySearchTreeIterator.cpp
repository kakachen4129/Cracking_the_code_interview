/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        p = root;  
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (p != nullptr || st.empty() != true);
    }

    /** @return the next smallest number */
    int next() {
        while (p != nullptr){
            st.push(p);
            p = p->left;
        }
        TreeNode* tmp = st.top();
        st.pop();
        p = tmp->right;
        return tmp->val;
    }
private:
    TreeNode *p;
    stack<TreeNode*> st;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */