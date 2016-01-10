class Solution {
public:
    bool hasOp(const string &s){
        int n = s.length();
        for (int i = 0; i < n; i++){
            if (s[i] == '+' || s[i] == '-' || s[i] == '*')
                return true;
        }
        return false;
    }
    vector<int> diffWaysToCompute(string input) {
        vector<int> ret, left, right;
        int n = input.length();
        if (!hasOp(input)){
            ret.push_back(atoi(input.c_str()));
            return ret;
        } else{
            for (int i = 0; i < n; i++){
                if (input[i] == '+' || input[i] == '-' || input[i] == '*'){
                    left = diffWaysToCompute(input.substr(0, i));
                    right = diffWaysToCompute(input.substr(i+1, n-i-1));
                    for (int j = 0; j < left.size(); j++)
                        for (int k = 0; k < right.size(); k++)
                            ret.push_back(calc(left[j], right[k], input[i]));
                }
            }
        }
        return ret;
    }
    int calc(int a, int b, char op){
        switch(op){
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            default : return 0;
        }
    }
};