/*https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 *time:
 *easy
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int len = (int)numbers.size();
		vector<int> res;

		int st = 0, ed = len - 1;
		while (st < ed) {
			if (numbers[st] + numbers[ed] == target) {
				res.push_back(st + 1);
				res.push_back(ed + 1);
				break;
			}			
			
			if (numbers[st] + numbers[ed] < target) {
				st++;
			} else {
				ed--;
			}
		}
	return res;
		
	}
};

int main() {
    Solution sol;

    vector<int> nums = {2, 7, 11, 15};
    vector<int> res = sol.twoSum(nums, 9);
    cout << res[0] << "," << res[1] << endl;

    return 0;
}
