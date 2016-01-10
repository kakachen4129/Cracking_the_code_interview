class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true);
        // Loop's ending condition is i * i < n instead of i < sqrt(n)
        // to avoid calling an expensive function sqrt().
        for (int i = 2; i * i < n; i++){
            // has traverse 2, need not to try 4, 6, 8 and so on
            if (isPrime[i] == false)    continue;
            // optimal j should start from i * i
            for (int j = i * 2; j < n; j += i)
                isPrime[j] = false;
        }
        int cnt = 0;
        for (int i = 2; i < n; i++)
            if (isPrime[i] == true) 
                cnt++;
        return cnt;
    }
};