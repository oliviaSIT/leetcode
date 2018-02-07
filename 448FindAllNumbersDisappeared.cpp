/*https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
 *time 30min
 * if the number has appeared -> nums(number - 1) < 0
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
        vector<int> findDisappearedNumbers(vector<int>& nums) {
        	if (nums.empty())
			return {};
		
		for (int i = 0; i < nums.size(); i++) {
			int idx = abs(nums[i]) - 1;
			if (nums[idx] > 0)
				nums[idx] = -nums[idx];
		}

		vector<int> res;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > 0)
				res.push_back(i + 1);
		}

		return res;
        }

};

int main() {
    Solution sol;

    vector<int> nums = {4,3,2,7,8,2,3,1};
    for (int &i : sol.findDisappearedNumbers(nums))
        cout << i << " ";
    cout << endl;

    return 0;
}
