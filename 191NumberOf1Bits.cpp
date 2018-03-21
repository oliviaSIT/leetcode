/*https://leetcode.com/problems/number-of-1-bits/description/
 *time:12min
 *solution: bit
 *easy
 */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) 
                count++;
        }
        
        return count;
    }
};
