class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        queue<TreeNode*> q;
        q.push(root);
        while (q.empty() != true){
            TreeNode *tmp = q.front();
            q.pop();
            if (tmp == nullptr){
                data += "n$";
            } else{
                data += to_string(tmp->val) + "$";
                q.push(tmp->left);
                q.push(tmp->right);
            }
        }
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        int cnt = 0;
        queue<TreeNode*> q;
        bool isNull = false;
        int val = getVal(cnt, isNull, data);
        if (isNull) return root;
        root = new TreeNode(val);
        q.push(root);
        while (q.empty() != true){
            TreeNode *tmp = q.front();
            q.pop();
            isNull = false;
            val = getVal(cnt, isNull, data);
            if (isNull){
                tmp->left = nullptr;
            } else{
                tmp->left = new TreeNode(val);
                q.push(tmp->left);
            }
            isNull = false;
            val = getVal(cnt, isNull, data);
            if (isNull){
                tmp->right = nullptr;
            } else{
                tmp->right = new TreeNode(val);
                q.push(tmp->right);
            }
        }
        return root;
    }
    
    int getVal(int &cnt, bool &isNull, const string &str){
        string sub;
        int t;
        if ((t = str.find('$', cnt)) != string::npos){
            sub = str.substr(cnt, t-cnt);
            cnt = t + 1;
        }
        if (sub.empty())  return 0;
        if (sub == "n"){
            isNull = true;
            return 0;
        }
        return atoi(sub.c_str());
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
