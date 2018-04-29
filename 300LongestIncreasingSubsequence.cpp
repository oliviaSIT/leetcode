/*https://leetcode.com/problems/longest-increasing-subsequence/description/
 *time:48min
 *solution:dp
 *medium
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;

		vector<int> tail(nums.size(), 0);
		int length = 1;//always points empty slot in tail

		tail[0] = nums[0];
		for (size_t i = 1; i < nums.size(); i++) {
			if (nums[i] < tail[0])
				// new smallest value
				tail[0] = nums[i];
			else if (nums[i] > tail[length - 1])
				// nums[i] extends largest subsequence
				tail[length++] = nums[i];
			else
				// nums[i] will become end candidate of an existing subsequence or
				// Throw away larger elements in all LIS, to make room for upcoming grater elements than nums[i]
				// (and also, nums[i] would have already appeared in one of LIS, identify the location and replace it)
				tail[CeilIndex(tail, -1, length - 1, nums[i])] = nums[i];
		}

		return length;
	}
	
	
	// Binary search (note boundaries in the caller)
	int CeilIndex(vector<int> &nums, int l, int r, int key) {
		while (r - l > 1) {
			int m = l + (r - l) / 2;
			if (nums[m] >= key)
				r = m;
			else
				l = m;
		}

		return r;
	}
};

int main() {
	vector<int> v{ 2, 5, 3, 7, 11, 8, 10, 13, 6 };
	Solution sol;
	cout << "Length of Longest Increasing Subsequence is " << sol.lengthOfLIS(v) << endl;
	return 0;
}
