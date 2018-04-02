/*https://leetcode.com/problems/subsets-ii/description/
 *time:
 *solution
 *medium
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() == 0)
			return res;

		vector<int> subset;
		sort(nums.begin(), nums.end());

		for (int i = 1; i <= nums.size(); i++)
			help(res, subset, nums, i, 0);
		
		res.push_back({});
		return res;
	}

	void help(vector<vector<int>>& res, vector<int> subset, vector<int>& nums, int k, int st) {
		if (st == k) {
			//subset.push_back(nums[st]);
			res.push_back(subset);
			return;
		}

		if (st > k)
			return;

		for (int i = st; i < nums.size(); i++) {
			subset.push_back(nums[i]);
			help(res, subset, nums, k, i + 1);
			subset.pop_back();
		
			while (i < nums.size() - 1 && nums[i] = nums[i + 1])
				i++;	
		}
	}
};
