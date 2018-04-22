/*https://leetcode.com/problems/maximum-product-subarray/description/
 *time:42min
 *solution: dp
 *medium
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int n = nums.size();
		if (n <= 0) return 0;
		int ret, curMax, curMin;
		ret = curMax = curMin = nums[0];
		for (int i = 1; i < n; i++) {
			int temp = curMax;
			curMax = max(max(curMax * nums[i], curMin * nums[i]), nums[i]);
			curMin = min(min(temp * nums[i], curMin * nums[i]), nums[i]);
			ret = max(ret, curMax);
		}
		return ret;
	}
};

int main() {
	Solution sol;
	vector<int> nums{ 2,3,-2,4 };
	cout << sol.maxProduct(nums) << endl;
	return 0;
}
