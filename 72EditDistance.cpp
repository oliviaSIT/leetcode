/*https://leetcode.com/problems/edit-distance/description/
 *time:23min
 *solution:dp
 *hard
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDistance(const string A, const string B) {
    	int a_len = A.length();
	    int b_len = B.length();	

	    if (a_len == 0)
		    return b_len;

    	if (b_len == 0)
	    	return a_len;
	
	    vector<vector<int> > dp;
            for(int i = 0; i < a_len + 1; i++) {
                vector<int> one(b_len + 1, 0);
                dp.push_back(one);
            }
		

	    for(int i = 0; i < a_len + 1; i++) {
                dp[i][0] = i;
            }
        for(int j = 0; j < b_len + 1; j++) {
            dp[0][j] = j;
        }


	    for (int i = 1; i < a_len + 1; i++) {
		    for (int j = 1; j < b_len + 1; j++) {
			    if (A[i - 1] == B[j - 1]) {
				    dp[i][j] = dp[i - 1][j - 1];
			    }else {
				    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
			    }
		    }
	    }
	
        
        return dp[a_len][b_len];

    }
};

int main() {
	Solution sol;
	cout << sol.minDistance("aab", "aac") << endl;
	return 0;
}
