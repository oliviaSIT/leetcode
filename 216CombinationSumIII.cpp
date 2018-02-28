/*https://leetcode.com/problems/combination-sum-iii/description/
 *time:
 *solution:
 *medium
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> res;
		vector<int> combine;

		combination(res, combine, k, n, 1);
		return res;
	}

private:
	void combination(vector<vector<int>>& res, vector<int>& combine, int k , int n, int st) {
		if (n == 0 && k == 0) {
			res.push_back(combine);
			return;
		}

	
		for (int i = st; i < 10 && i <= n; i++) {
			combine.push_back(i);
			combination(res, combine, k - 1, n - i, i + 1);
			combine.pop_back();
		}
	}
};
