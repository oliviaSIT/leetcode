/*https://leetcode.com/problems/non-decreasing-array/description/
 *time: 25min
 *solution
 *easy
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		for (int i=0; i < nums.size()-1; i++){
			if (nums[i] > nums[i+1]){
				int temp = nums[i];

                	// "erase" nums[i], then check if nums is sorted without nums[i]
			nums[i] = nums[i+1];
			if (is_sorted(nums.begin(), nums.end()))
				return true;

			// "erase" nums[i+1], then check if nums is sorted without nums[i+1]
			nums[i+1] = nums[i] = temp;
			if (is_sorted(nums.begin(), nums.end()))
				return true;
                
			// nums is NOT sorted (without nums[i] XOR without nums[i+1])
			return false;
			}
		}
		return true;
	}
};

int main() {
	Solution sol;
	vector<int> v{4, 2, 1};
	cout << sol.checkPossibility(v) << endl;
	return 0;
}
