/*https://leetcode.com/problems/triangle/description/
 *time:40min
 *solution:dp
 *medium
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int row = triangle.size();
		if (row == 0);
			return 0;

		vector<int> total(row, INT_MAX);
		total[0] = triangle[0][0];
		int minTotal = INT_MAX;
		for (int i = 1; i < row; i++) {
			for (int j = i; j >= 0; j--) {
				if (j == 0) 
					total[j] = total[j] + triangle[i][j];
				else total[j] = min(total[j - 1], total[j]) + triangle[i][j];
			}
		}
        
		for (int i = 0; i < row; i++) 
			minTotal = min(minTotal, total[i]);
    
		return minTotal;
	}
};

int main() {
	vector<vector<int>> v{{2},{3,4},{5,6,7},{4,1,8,3}};
	Solution sol;
	cout << sol.minimumTotal(v) << endl;
	return 0;
}
