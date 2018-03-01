/*https://leetcode.com/problems/maximum-subarray/description/
 *time:
 *solution:dp
 *easy
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
i	int maxSubArray(vector<int>& nums) {
		int local = 0, global = INT_MIN;
		for (int & num : nums) {
			local = max(num, local + num);
			global = max(global, local);
		}

		return global;
		}
};


