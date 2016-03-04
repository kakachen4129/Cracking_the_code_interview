class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        int n = L.size();
        if (n == 0)
            return ret;
        int len = L[0].length();
        unordered_map<string, int> map, bak;
        for (int i = 0; i < n; i++)
            bak[L[i]]++;
        for (int i = 0; i + n*len - 1 < S.length(); i++){
            map.clear();
            bool flag = true;
            for (int j = 0; j < n; j++){
                string ss = S.substr(i+j*len, len);
                if (bak.find(ss) == bak.end()){
                    flag = false;
                    break;
                }
                map[ss]++;
                if (map[ss] > bak[ss]){
                    flag = false;
                    break;
                }
            }
            if (flag == true)
                ret.push_back(i);
        }
        return ret;
    }
};
