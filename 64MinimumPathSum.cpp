/*https://leetcode.com/problems/minimum-path-sum/description/
 *time:22min
 *solution:dp similiar as Unique Path
 *medium
 */

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = 0;
        if (m != 0)
            n = grid[0].size();
        
        if (m * n == 0)
            return 0;
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        
        for (int i = 1; i < m; i++) 
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        
        for (int j = 1; j < n; j++)
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++)
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
        
        return dp[m - 1][n - 1];
        
    }
};
