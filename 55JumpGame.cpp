/*https://leetcode.com/problems/jump-game/description/
 *time:
 *solution
 *medium
 */

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int len = nums.size();
		if (len < 2)
			return true;

		int index = 0, dis = 0;
		while (dis >= index) {
			if (index + nums[index] > dis)
				dis = index + nums[index];

			index++;
			if (dis >= len - 1)
				return true;
		}

		return false;
	}
};
