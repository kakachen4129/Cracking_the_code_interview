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
    /*
    // use recursion, if cur height is greater than max height, add node to the result
    void getRight(vector<int> &ret, TreeNode* root, int& maxH, int curH){
        if (root == NULL)   return;
        curH++;
        if (curH > maxH){
            maxH = curH;
            ret.push_back(root->val);
        }
        getRight(ret, root->right, maxH, curH+1);
        getRight(ret, root->left, maxH, curH+1);
        curH--;
    }
    vector<int> rightSideView(TreeNode* root) {
        int maxH = 0;
        vector<int> ret;
        getRight(ret, root, maxH, 0);
        return ret;
    }*/
    
    // use level traverse idea, use a queue
    vector<int> rightSideView(TreeNode *root){
        vector<int> ret;
        queue<TreeNode*> q;
        if (root != NULL)  q.push(root);
        while (q.empty() != true){
            ret.push_back(q.back()->val);
            int n = q.size();
            for (int i = 0; i < n; i++){
                TreeNode *tmp = q.front();
                q.pop();
                if (tmp->left != NULL)
                    q.push(tmp->left);
                if (tmp->right != NULL)
                    q.push(tmp->right);
            }
        }
        return ret;
    }
};