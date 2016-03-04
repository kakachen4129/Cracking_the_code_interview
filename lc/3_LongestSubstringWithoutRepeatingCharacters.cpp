class Solution {
public:
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> counter;
    int max = 0;
    int l = 0;
    for (int i = 0; i < s.size(); i++){
        counter[s[i]]++;
        while (counter[s[i]] > 1 && l <= i){
            l++;
            counter[s[l-1]]--;
        }
        if (i - l + 1 >= max)
            max = i - l + 1;
    }
    return max;          
}
};