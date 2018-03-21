/*https://leetcode.com/problems/power-of-four/description/
 *time:23min
 *solution: log2(n) == even
 *easy
 */

class Solution {
public:
    bool isPowerOfFour(int num) {
        return log2(num) == (int)log2(num) && (int)log2(num) % 2 == 0;
    }
};


