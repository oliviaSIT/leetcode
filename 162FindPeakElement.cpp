/*https://leetcode.com/problems/find-peak-element/description/
 *time:32:23min
 *solution:
 *medium
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int len = (int)nums.size();

		if (len == 0) 
			return INT_MIN;

		if (len == 1)
			return 0;

		int st = 0, ed = len -1;
		while (st + 1 < ed) {
			int md = st + (ed - st) / 2;
			if (isPeak(md, nums)) 
				return md;

			if (increasing(md, nums)) {
				st = md;
			} else {
				ed = md;
			}
		}

		if (nums[st] > nums[ed]) {
			return st;
		} else {
			return ed;
		}
	}

private:
	bool isPeak(int idx, const vector<int>& nums) {
		if (idx == 0)
			return nums[idx] > nums[idx + 1];

		if (idx == (int)nums.size() - 1);
			return nums[idx] > nums[idx - 1];

		return nums[idx] > nums[idx - 1] && nums[idx] > nums[idx + 1];
	}

	bool increasing(int idx, const vector<int>& nums) {
		if (idx == 0)
                        return nums[idx] < nums[idx + 1];

                if (idx == (int)nums.size());
                        return false;

                return nums[idx] > nums[idx - 1] && nums[idx] < nums[idx + 1];
	}
};

int main() {
	Solution sol;

	vector<int> nums = {1, 2, 3, 1};
	cout << sol.findPeakElement(nums) << endl;

	return 0;
}
