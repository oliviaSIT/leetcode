/*https://leetcode.com/problems/combination-sum-ii/description/
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
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> res;

		if (candidates.size() == 0)
			return res;
		
		sort(candidates.begin(), candidates.end());
		vector<int> combine;
		combinationSum2(candidates, res, combine, target, 0);
		return res;
	}

	void combinationSum2(vector<int>& candidates, vector<vector<int>>& res, vector<int>& combine, int target, int st) {
		if (target == 0)
			res.push_back(combine);

		for (int i = st; i < (int)candidates.size() && target >= candidates[i]; i++) {
			combine.push_back(candidates[i]);
			combinationSum2(candidates, res, combine, target - candidates[i], i + 1);
			combine.pop_back();

			while( (i + 1) < candidates.size() && candidates[i + 1] == candidates[i]) 
				i++;
		}
	}
};

