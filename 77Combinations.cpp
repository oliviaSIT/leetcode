/*https://leetcode.com/problems/combinations/description/
 *time:61min
 *solution:DFS
 *medium
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> cur;

		DFS(res, cur, n, k , 1);
		return res;
	}

private:
	void DFS(vector<vector<int>>& res, vector<int>& cur, int n, int k, int level) {
		if ((int)cur.size() == k) {
			res.push_back(cur);
			return;
		}

		// cut the branch
		if ((int)cur.size() > k) {
			return;
		}

		for (int i = level; i <= n; i++) {
			cur.push_back(i);
			DFS(res, cur, n, k, i + 1);
			cur.pop_back();
		}

		return;
	}
};

int main() {
	Solution sol;
	vector<vector<int>> res = sol.combine(5, 2);
	for (int i = 0; i < (int)res.size(); i++) {
		for (int j = 0; j < (int)res[0].size(); j++)
			cout << res[i][j] << ' ';

		cout << endl;
	}

	return 0;
}
