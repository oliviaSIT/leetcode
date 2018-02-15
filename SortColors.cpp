/*https://leetcode.com/problems/sort-colors/description/
 *time:34:22min
 *solution:Use two pointers point to the end of sorted part. Notice if swap 1, need first swap with the next 1 position, which is 2 already, so don't move pointer ahead.
 *medium
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int white = -1, blue = -1;
		for (int i = 0; i < int(nums.size()); i++) {
			if (nums[i] == 0) {
				white++;
				blue++;
				swap(nums[white], nums[i]);//let red be the first part of the list
				if (blue == white) 
					continue;

				swap(nums[blue], nums[i]);
			} else if (nums[i] == 1) {
				blue++;
				swap(nums[blue], nums[i]);
			}
		}
	}
};
