class Solution {
public:
    // assuming no overflow for num1 and num2
    int compareVersion(string version1, string version2) {
        int idx1 = 0, idx2 = 0;
        while (idx1 < version1.size() || idx2 < version2.size()){
            int num1 = 0;
            int num2 = 0;
            while (idx1 < version1.size() && version1[idx1] != '.')
                num1 = num1 * 10 + version1[idx1++] - '0';
            idx1++;
            while (idx2 < version2.size() && version2[idx2] != '.')
                num2 = num2 * 10 + version2[idx2++] - '0';
            idx2++;
            if (num1 > num2)    return 1;
            if (num1 < num2)    return -1;
        }
        return 0;
    }
};