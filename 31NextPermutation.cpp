/*https://leetcode.com/problems/next-permutation/description/
 *time:46min
 *solution:find the first number which is larger than next one, change the number, reverse the order
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() < 2)
			return;
		
		int i = nums.size() - 1;
		while (i > 0 && nums[i] <= nums[i - 1]) {
			i--;
		}

		if (i > 0) {
			int j = bigger(nums, i);
			swap(nums[i - 1], nums[j]);
		}

		reverse(nums.begin() + i, nums.end());
	}

private:
	int bigger(vector<int>& nums, int i) {
		int j = nums.size() - 1;
		while (nums[j] <= nums[i - 1])
			j--;

		return j;	
	}
};

		
