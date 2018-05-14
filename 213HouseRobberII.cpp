/*https://leetcode.com/problems/house-robber-ii/description/
 *time:23min
 *solution:DP 分为2类：抢第一套房，不抢第一条房
 *meidum
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;

		if (nums.size() == 1)
			return nums[0];

		int r_rf = nums[0], nr_rf = 0, r_nrf = 0, nr_nrf = 0;
		for (int i = 1; i < nums.size(); i++) {
			int pre_rf = max(r_rf, nr_rf);
			int pre_nrf = max(r_nrf, nr_nrf);
			r_rf = nr_rf + nums[i];
			nr_rf = pre_rf;
			r_nrf = nr_nrf + nums[i];
			nr_nrf = pre_nrf;
		}

		return max(nr_rf, max(r_nrf, nr_nrf));
	}
};
