class Solution {
public:
    // DFS with memo
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        vector<bool> possible(n+1, true);
        vector<string> res;
        string cur;
        getSen(res, s, 0, cur, dict, possible);
        return res;
    }
    
    bool getSen(vector<string> &res, const string &s, int pos, 
        string cur, const unordered_set<string> &dict, vector<bool> &possible){
        if (pos >= s.size()){
            cur.erase(cur.end()-1);
            res.push_back(cur);
            return true;
        }
        bool ret = false;
        for (int i = pos; i < s.size(); i++){
            string word = s.substr(pos, i-pos+1);
            // possible is to record if this pos is a possible point for a sentence
            // not possible, cut out
            if (possible[i+1] && dict.find(word) != dict.end()){
                ret = getSen(res, s, i+1, cur+word+" ", dict, possible) || ret;
            }
        }
        // after geting all the results, assign possible
        possible[pos] = ret;
        return ret;
    }
};