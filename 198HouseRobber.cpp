/*https://leetcode.com/problems/house-robber/description/
 *time:33:32min
 *Solution: dp
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
        int rob(vector<int>& nums) {
        	const int n = nums.size();
        	if (n == 0) return 0;
        	if (n == 1) return nums[0];
        	if (n == 2) return max(nums[0], nums[1]);
        
		vector<int> money(n, 0);
        	money[0] = nums[0];
        	money[1] = max(nums[0], nums[1]);
        	for (size_t i = 2; i < n; i++)
            	money[i] = max(money[i-2] + nums[i], money[i-1]);
        
		return money[n-1];
        }
};
