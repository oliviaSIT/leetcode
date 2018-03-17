/*https://leetcode.com/problems/first-missing-positive/description/
 *time:60min
 *solution: bucket sorting
 *hard
 */

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		if (nums.size() == 0)
			return 1;

		bucketSort(nums);

		for (int i = 0; i < (int)nums.size(); i++) {
			if (nums[i] != i + 1)
				return i + 1;
		}

		return nums.size() + 1;
	}

	void bucketSort(vector<int>& nums) {
		for (int i = 0; i < (int)nums.size(); i++) {
			while (nums[i] > 0 && nums[i] <= (int)nums.size() && nums[i] != i + 1) {
			int val = nums[i];
			int pos = val - 1;
			if (nums[pos] == val)
				break;

			int t = nums[pos];
			nums[pos] = val;
			nums[i] = t;
			}
		}
	}
};
