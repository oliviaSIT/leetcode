/*https://leetcode.com/problems/count-numbers-with-unique-digits/description/
 *time:24min
 *solution: recurse
 *medium
 */

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;
        
        return help(n) + countNumbersWithUniqueDigits(n - 1);
    }
    
    int help(int n) {
        int res = 9;
        for (int i = 0; i < n - 1; i++)
            res *= (9 - i);
        
        return res;
    }
};
