/*https://leetcode.com/problems/find-the-duplicate-number/description/
 *time:5min
 *medium
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size() - 1; i++) {
            for (int j = i + 1; j < (int)nums.size(); j++) {
                if (nums[i] == nums[j])
                    return nums[i];
            }
        }
    }
};
