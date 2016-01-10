class Solution {
public:
    bool isAnagram(const string &s1, const string &s2){
        int n1 = s1.size();
        int n2 = s2.size();
        if (n1 != n2)   return false;
        unordered_map<char, int> map1, map2;
        for (int i = 0; i < n1; i++){
            map1[s1[i]]++;
            map2[s2[i]]++;
        }
        return map1 == map2;
    }
};