/*https://leetcode.com/problems/number-of-islands/description/
 *time:58min
 *solution:dfs
 *medium
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int m = grid.size();

		if (m == 0)
			return 0;

		int n = grid[0].size();

		if (n == 0)
			return 0;

		int res = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == '1') {
					res++;
					dfs(grid, m, n, i, j);
				}
			}
		}

		return res;
	}

	void dfs(vector<vector<char>>& grid, int m, int n, int i, int j) {
		if (i < 0 || i >= m || j < 0 || j >= n)
			return;

		if (grid[i][j] == '1') {
			grid[i][j] = '2';
			dfs(grid, m, n, i - 1, j);
			dfs(grid, m, n, i + 1, j);
			dfs(grid, m, n, i, j - 1);
			dfs(grid, m, n, i, j + 1);
		}
	}
};

int main() {
	
}
