class Solution {
public:
    // denominator can not be 0
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        int a = numerator < 0 ? 1 : 0;
        int b = denominator < 0 ? 1 : 0;
        long long n = abs((long long)numerator);
        long long d = abs((long long)denominator);
        bool isNeg = a ^ b;
        string ret;
        if (isNeg)  ret += "-";
        ret += to_string(n/d);
        if (n % d == 0) return ret;
        ret += ".";
        n = n % d;
        unordered_map<long, int> map;
        string decimal;
        int idx = 0;
        while (n != 0){
            n = n * 10;
            if (map.find(n) != map.end())   break;
            map[n] = idx++;
            long long remainder = n % d;
            long long quotient = n / d;
            decimal += to_string(quotient);
            if (remainder == 0) return ret + decimal;
            n = remainder;
        }
        decimal.insert(map[n], "(");
        ret += decimal + ')';
        return ret;
    }
};