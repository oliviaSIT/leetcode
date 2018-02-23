/*https://leetcode.com/problems/array-partition-i/description/
 *time: 12min
 *easy
 */

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < (int)nums.size(); i+=2) {
            res += nums[i];
        }
        return res;
    }
};
