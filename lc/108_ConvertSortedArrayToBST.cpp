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
    // top down
    TreeNode* convert(const vector<int> &nums, int l, int r){
        if (l > r)  return NULL;
        int mid = l + (r - l) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = convert(nums, l, mid-1);
        root->right = convert(nums, mid+1, r);
        return root;
    }*/
    
    // bottom up 
    TreeNode* convert(const vector<int> &nums, int l, int r){
        if (l > r)  return NULL;
        int mid = l + (r - l) / 2;
        TreeNode* left = convert(nums, l, mid-1);
        TreeNode* right = convert(nums, mid+1, r);
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = left;
        root->right = right;
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return convert(nums, 0, n-1);
    }
};