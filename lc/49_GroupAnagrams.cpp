class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> map;
        for (int i = 0; i < strs.size(); i++){
            string str = strs[i];
            sort(str.begin(), str.end());
            map[str].push_back(strs[i]);
        }
        for (const auto &it : map){
            vector<string> tmp = it.second;
            sort(tmp.begin(), tmp.end());
            ret.push_back(tmp);
        }
        return ret;
    }
};