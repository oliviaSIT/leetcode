/*https://leetcode.com/problems/product-of-array-except-self/description/
 *time:31min
 *solution:[1,a0,a0*a1,a0*a1*a2] [a3*a2*a1,a3*a2,a3,1]
 *medium
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		if (nums.size() <= 1)
			return nums;

		vector<int> res(nums.size(), 1);

		for (int i = 1; i < nums.size(); i++)
			res[i] = res[i - 1] * nums[i - 1];

		int t = 1;
		for (int i = nums.size() - 1; i >= 0; i--) {
			res[i] *= t;
			t = nums[i];
		}

		return res;
	}
};
