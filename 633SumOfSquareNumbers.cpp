/*https://leetcode.com/problems/sum-of-square-numbers/description/
 *time:12min
 *easy
 */

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i=0;i<=sqrt(c);i++) {
            int t=sqrt(c-i*i);
            if(t*t==c-i*i) return true;
        }
        return false;
    }
};
