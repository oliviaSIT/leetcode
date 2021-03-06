/*https://leetcode.com/problems/unique-paths-ii/description/
 *time:30min
 *solution:similiar as Unique path I, when there is obstacle, dp[i][j] = 0
 *medium
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if(obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1) 
			return 0;

		int m = obstacleGrid.size(), n = obstacleGrid[0].size();

		vector<vector<int>> dp(m, vector<int>(n, 1));

		for (int i = 1; i < m; i++) {
			if (obstacleGrid[i][0] == 0)
				dp[i][0] = dp[i - 1][0];
			else dp[i][0] = 0;
		}

		for (int j = 1; j < n; j++) {
                        if (obstacleGrid[0][j] == 0)
                                dp[0][j] = dp[0][j - 1];
                        else dp[0][j] = 0;
                }

		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				if (obstacleGrid[i][j] == 0)
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				else dp[i][j] = 0;
			}
		}

		return dp[m - 1][n - 1];
	}
};

int main() {
	vector<vector<int>> ob{{0,0,0},{0,1,0},{0,0,0}};
	Solution sol;
	cout << sol.uniquePathsWithObstacles(ob) << endl;
	return 0;
}	
