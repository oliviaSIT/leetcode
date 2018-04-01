/*https://leetcode.com/problems/subsets/description/
 *time:50min
 *solution:backtracking
 *medium
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() == 0)
			return res;

		for (int i = 1; i <= (int)nums.size(); i++) {
			vector<int> cur;
			combine(res, cur, nums, i, 0);
		}

		res.push_back({});

		return res;
	}

private:
	void combine(vector<vector<int>>& res, vector<int>& cur, vector<int> nums, int n, int st) {
		if (cur.size() == n) {
			res.push_back(cur);
			return;
		}

		for (int i = st; i < (int)nums.size(); i++) {
			cur.push_back(nums(i));
			combine(res, cur, nums, n, i + 1);
			cur.pop_back();
		}
	} 
};

int main() {
	Solution sol;
	vector<int> v{ 1, 2, 3 };
	vector<vector<int>> res = sol.subsets(v);
	for (int i = 0; i < (int)res.size(); i++) {
		for (int j = 0; j < (int)res[i].size(); j++) {
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
