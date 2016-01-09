class Solution {
public:
    /*int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }*/
    int addDigits(int num){
        if (num >= 0 && num <= 9)
            return num;
        int n = 0;
        while (num != 0){
            n += num % 10;
            num = num / 10;
        }
        return addDigits(n);
    }
};