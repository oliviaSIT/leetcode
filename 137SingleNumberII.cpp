/*https://leetcode.com/problems/single-number-ii/description/
 *time:49min
 *solution:二进制，从高位开始，对数组中元素的每一位进行相加，mod3
 *medium
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        
        for (int i = 31; i >= 0; i--) {
            int sum = 0, mask = 1 << i;
            for (int j = 0; j < n; j++) {
                if (nums[j] & mask)
                    sum++;
            }
            
            res = (res << 1) + (sum % 3);
        }
        
        return res;
    }
};
