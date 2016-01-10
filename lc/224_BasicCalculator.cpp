class Solution {
public:
    /*int calculate(string s){
        string str = removeSpace(s);
        return calc(str);
    }
    int calc(string str){
        int n = str.size();
        if (str[0] == '('){
            int idx = findMatching(str);
            if (idx == n-1){
                return calc(str.substr(1, n-2));
            } else{
                return op(str[idx+1], calc(str.substr(1, idx-1)), calc(str.substr(idx+2, n-idx-1)));
            }
        } else{
            int idx = findFirstOp(str);
            if (idx == n){
                return atoi(str.c_str());
            } else{
                return op(str[idx+1], calc(str.substr(1, idx-1)), calc(str.substr(idx+1, n-idx-1)));
            }
        }
    }
    int findMatching(const string &str){
        int n = str.size();
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if (str[i] == '(')  cnt++;
            else if (str[i] == ')'){
                cnt--;
                if (cnt == 0)   return i;
            }
        }
        return n;
    }
    int findFirstOp(const string &str){
        int n = str.size();
        for (int i = 0; i < n; i++){
            if (str[i] == '+' || str[i] == '-')
                return i;
        }
        return n;
    }
    int op(char ch, int a, int b){
        if (ch == '+')  return a + b;
        else if (ch == '-')    return a - b;
        else return 0;
    }
    string removeSpace(const string &str){
        string ret;
        for (int i = 0; i < str.size(); i++)
            if (str[i] != ' ')
                ret += str[i];
        return ret;
    }*/
    int calculate(string s){
        string str = removeSpace(s);
        return calc(str);
    }
    int calc(string str){
        int res = 0;
        char op = '+';
        int n = str.size();
        int i = 0;
        while (i < n){
            if (isNumber(str[i])){
                int t = 0;
                while (i < n && isNumber(str[i]))
                    t = t * 10 + str[i++] - '0';
                res = getResult(op, res, t);
            } else{
                int idx = findMatching(i, str);
                res = getResult(op, res, calc(str.substr(i+1, idx-i-1)));
                i = idx + 1;
            }
            if (i >= n) return res;
            else    op = str[i++];
        }
        return res;
    }
    bool isNumber(char c){
        return c >= '0' && c <= '9';
    }
    int findMatching(int start, const string &str){
        int n = str.size();
        int cnt = 0;
        for (int i = start; i < n; i++){
            if (str[i] == '(')  cnt++;
            else if (str[i] == ')'){
                cnt--;
                if (cnt == 0)   return i;
            }
        }
        return n;
    }
    int getResult(char ch, int a, int b){
        if (ch == '+')  return a + b;
        else if (ch == '-')    return a - b;
        else return 0;
    }
    string removeSpace(const string &str){
        string ret;
        for (int i = 0; i < str.size(); i++)
            if (str[i] != ' ')
                ret += str[i];
        return ret;
    }
};