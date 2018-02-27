/*https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *time:60min
 *solution:
 *medium
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return -1;

		int st = 0, ed = nums.size() - 1;
		while (st <= ed) { //maybe nums[st] or nums[ed] equals to target
			int md = st + (ed - st) / 2;
			if (nums[md] == target)
				return md;

			if (nums[md] < target) {
				if (target >= nums[st] && nums[md] < nums[st])
					ed = md - 1;
				else st = md + 1;
			} else {
				if (target <= nums[ed] && nums[ed] < nums[md]) 
					st = md + 1;
				else ed = md - 1;
			}
		}
		return -1;
	}
};
