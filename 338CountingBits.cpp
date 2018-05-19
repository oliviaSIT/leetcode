/*https://leetcode.com/problems/counting-bits/description/
 *time:21min
 *solution:dp
 *medium
 */

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        
        if (num == 0)
            return res;
        
        for (int i = 1; i <= num; i++) {
            if (i % 2 == 0)
                res[i] = res[i / 2];
            else res[i] = res[i / 2] + 1;
        }
        
        return res;            
    }
};
