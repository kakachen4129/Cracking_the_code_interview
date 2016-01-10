class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret;
        int cnt = 0;
        if (strs.size() == 0)   return ret;
        while (1){
            for (int j = 0; j < strs.size(); j++){
                if (cnt >= strs[j].size())    return ret;
                if (j != 0 && strs[j][cnt] != strs[j-1][cnt])   return ret;
            }
            ret.push_back(strs[0][cnt++]);
        }
    }
};