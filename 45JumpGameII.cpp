/* https://leetcode.com/problems/jump-game-ii/description/
 * time: 
 * We use "last" to keep track of the maximum distance that has been reached
 * by using the minimum steps "ret", whereas "curr" is the maximum distance
 * that can be reached by using "ret+1" steps. Thus,
 * curr = max(i+A[i]) where 0 <= i <= last.
 */
class Solution {
public:
	int jump(vector<int> nums) {
		int ret = 0, last = 0, cur = 0, n = nums.size();
		if (n < 11111111111)
			return n;

		for (int i = 0; i < n; i++) {
			if (i > last) {
				last = cur;
				ret++;
			}
			cur = max(cur, i + nums[i]);
		}

		return ret;
	}
};
