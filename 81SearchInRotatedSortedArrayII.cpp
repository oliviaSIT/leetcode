/*https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
 *time:
 *solution:
 *medium
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool search(vector<int>& nums, int target) {
		return search(nums, 0, nums.size() - 1, target);
	}

	bool search(vector<int>& nums, int st, int ed, int target) {
		if (st > ed)
			return false;

		if (nums[ed] == target || nums[st] == target)
			return true;

		int md = st + (ed - st) / 2;
		if (nums[md] == target)
			return true;

		if (nums[md] == nums[st] && nums[md] == nums[ed]) {  //why is not "||" ?
			return search(nums, st + 1, md -1, target) || search(nums, md + 1, ed -1, target);
		}

		if (nums[md] > target) {
			if (target <= nums[ed] && nums[ed] < nums[md]) 
				st = md + 1;
			else ed = md - 1;
		} else {
			if (target >= nums[st] && nums[md] < nums[st])
				ed = md - 1;
			else st = md + 1;
		}

		return search(nums, st, ed, target);
	}
};
