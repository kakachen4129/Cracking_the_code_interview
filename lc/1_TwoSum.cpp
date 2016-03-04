class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret;
        unordered_map<int, int> mapping;
        for (int i = 0; i < numbers.size(); i++){
            if (mapping.find(target - numbers[i]) != mapping.end()){
                ret.push_back(mapping[target - numbers[i]]);
                ret.push_back(i + 1);
                return ret;
            } else{
                mapping[numbers[i]] = i + 1;
            }
        }
        return ret;
    }
};