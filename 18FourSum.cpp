/*https://leetcode.com/problems/4sum/description/
 *time:45min
 *medium
 *solution:first add two numbers, then use twoSum function
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<int> satisfy{0, 0, 0, 0};
		vector<vector<int>> res;

		sort(nums.begin(), nums.end());

		for (int i = 0; i < (int)nums.size() - 3; i++) {
			for (int j = i + 1; j < (int)nums.size() - 2; j++) {
				int sum0 = nums[i] + nums[j];
				int st = j + 1, ed = (int)nums.size() - 1;
				while (st < ed) {
					if (sum0 + nums[st] + nums[ed] == target) {
						satisfy[0] = nums[i];
						satisfy[1] = nums[j];
						satisfy[2] = nums[st];
						satisfy[3] = nums[ed];
						st++;ed--;
						res.push_back(satisfy);
					} else if (sum0 + nums[st] + nums[ed] < target) {
						st++;
					} else ed--;
				}
			}
		}

		std::vector<vector<int>>::iterator it;
		it = std::unique(res.begin(), res.end());
		res.resize(std::distance(res.begin(), it));
		return res;
	}
};

void print(vector<vector<int>> v) {
	for (int i = 0; i < (int)v.size(); i++) {
		for (int j = 0; j < (int)v[i].size(); j++) {
			cout << v[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	Solution sol;
	vector<int> v1{1, 0, -1, 0, -2, 2};
	vector<int> v2{1, 1, 1, 1, 1, 1};
	int t1 = 0, t2 = 4;
	print(sol.fourSum(v1, t1));
	print(sol.fourSum(v2, t2));

	return 0;
}
