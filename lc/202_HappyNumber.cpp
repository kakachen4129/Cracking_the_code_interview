class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while (set.find(n) == set.end()){
            if (n == 1) return true;
            set.insert(n);
            int sum = 0;
            while (n != 0){
                int t = n % 10;
                sum += t * t;
                n = n / 10;
            }
            n = sum;
        }
        return false;
    }
};