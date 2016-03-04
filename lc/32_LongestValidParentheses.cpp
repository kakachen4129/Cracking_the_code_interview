class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int lastRightP = -1;
        stack<int> st;
        int ret = 0;
        int len = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == '(')
                st.push(i);
            else{
                if (st.empty() != true){
                    st.pop();
                    if (st.empty() == true)
                        len = i - lastRightP;
                    else
                        len = i - st.top();
                    ret = (ret > len) ? ret : len;
                }
                else
                    lastRightP = i;
            }
        }
        return ret;
    }
};
