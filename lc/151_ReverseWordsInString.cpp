class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int start = 0, end;
        while ((end = s.find(" ", start)) != string::npos){
            if (start != end)
                reverse(s.begin()+start, s.begin()+end);
            start = end + 1;
        }
        if (start < s.size())
            reverse(s.begin()+start, s.end());
        int cnt = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == ' ' && (i == 0 || s[i-1] == ' '))
                continue;
            s[cnt++] = s[i];
        }
        s.resize(cnt);
        if (cnt != 0 && s[cnt-1] == ' ')
            s.erase(s.end()-1);
    }
};