/*https://leetcode.com/problems/contains-duplicate/description/
 *time:5min + 16min
 *solution: hash
 *easy
 */

/*
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (int i = 1; i < (int)nums.size(); i++) {
			if (nums[i - 1] == nums[i])
				return true;
		}
        
		return false;
	}
};
*/

class Solution {
public:
        bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> set;
		for (int num: nums) {
			if (set.find(num) != set.end())
				return true;
			else set.insert(num);
		}

		return false;
	}
};
