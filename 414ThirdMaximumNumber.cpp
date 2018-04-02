/*https://leetcode.com/problems/third-maximum-number/description/
 *time:12min
 *solution
 *easy
 */

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        
        int count = 0;
        int res;
        for (int i = 0; i < (int)nums.size(); i++) {
            res = nums[i];
            
            while  (i < (int)nums.size() - 1 && nums[i] == nums[i + 1])
                i++;
            
            count++;
            
            if (count == 3)
                break;
        }
        
        if (count != 3)
            return nums[0];
        
        return res;
    }
};
