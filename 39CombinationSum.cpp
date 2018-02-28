/*https://leetcode.com/problems/combination-sum/description/
 *time:
 *solution:
 *medium
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> res;
		vector<int> combine;
		combinationSum(candidates, target, res, combine, 0);
		return res;
	}

private:
	void combinationSum(vector<int>&candidates, int target, vector<vector<int>>&res, vector<int>&combine, int begin) {
		if (target == 0) {
			res.push_back(combine);
			return;
		}

		for (int i = begin; i < (int)candidates.size() && target >= candidates[i]; i++) {
			combine.push_back(candidates[i]);
			combinationSum(candidates, target - candidates[i], res, combine, i);
			combine.pop_back();
		}
	}
};
/*
int main() {
	Solution Sol;
	vector<int> v{2, 3, 6, 7};
//	cout << Sol.combinationSum(v, 7) << endl
}
*/
