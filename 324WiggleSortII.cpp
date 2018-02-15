/*https://leetcode.com/problems/wiggle-sort-ii/description/
 *time:
 *solution:First sort the array. Then cut array in the middle. To ensure the order, the last element of first half must smaller than last element of the second half
 *corner case:[4, 5, 5, 6]
 *medium
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		vector<int> tmp(nums.begin(), nums.end());
		sort(tmp.begin(), tmp.end());

		int firstEd = ((int)nums.size() - 1) / 2, secondEd = (int)nums.size() - 1;
		bool first = true;
		for (int i = 0; i < (int)nums.size(); i++) {
			if (first) {
				nums[i] = tmp[firstEd--];
				first = false;
			} else {
				nums[i] = tmp[secondEd--];
				first = true;
			}
		}
	}
};
