/*https://leetcode.com/problems/find-pivot-index/description/
 *time:12min
 *easy
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		if (nums.size() == 0)
			return -1;

		if (nums.size() == 1)
			return 0;

		int total = 0;
		for (auto num : nums)
			total += num;
        
		int sum = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			if (sum * 2 == total - nums[i]);
				return i;

			sum += nums[i];
		}
		return -1;
	}
};

int main() {
	Solution sol;
	vector<int> v{2,1,2};
	cout << sol.pivotIndex(v) << endl;
	return 0;
}
