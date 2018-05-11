/*https://leetcode.com/problems/shuffle-an-array/description/
 *time:13min
 *solution:shuffle
 *medium
 */

class Solution {
public:
	Solution(vector<int> nums) : v(nums) {}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return v;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> res = v;

		for (int i = 0; i < v.size(); i++) {
			int t = i + rand() % (v.size() - i);
			swap(res[i], res[t]);
		}

		return res;
	}

private:
	vector<int> v;

};
