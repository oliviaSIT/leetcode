/*https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
 *time:32min
 *solution: 2pointers
 *medium
 */

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 2)
			return nums.size();

		int st = 0, ed = 1;
		while (ed < (int)nums.size()) {
			if (nums[st] != nums[ed]) {
				if (ed - st > 2) {
					nums.erase(nums.begin() + st + 2, nums.begin() + ed);
					st += 2;
				}
				else st = ed;
				ed = st + 1;
			} else ed++;
		}

		if (ed - st > 2) 
			nums.erase(nums.begin() + st + 2, nums.begin() + ed);
		
		return nums.size();
	}
};
