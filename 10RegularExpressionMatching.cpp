/*https://leetcode.com/problems/regular-expression-matching/description/
 *time:
 *solution:dp, dp[i][j] means the case of s[0:i-1] and p[0:j-1]
 *hard
 */

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1,false));
        dp[0][0] = true;
        
        for(int i=0; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(p[j-1]!='.' && p[j-1]!='*') {
                    if(i>0 && s[i-1]==p[j-1] && dp[i-1][j-1])
                        dp[i][j] = true;
                }
                else if(p[j-1]=='.') {
                    if(i>0 && dp[i-1][j-1])
                        dp[i][j] = true;
                }
                else if(j>1) {  //'*' cannot be the 1st element
                    if(dp[i][j-1] || dp[i][j-2])  // match 0 or 1 preceding element
                        dp[i][j] = true;
                    else if(i>0 && (p[j-2]==s[i-1] || p[j-2]=='.') && dp[i-1][j]) // match multiple preceding elements
                        dp[i][j] = true;
                }
            }
        }
        return dp[m][n];
    }
};
