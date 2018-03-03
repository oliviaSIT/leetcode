/*https://leetcode.com/problems/pascals-triangle/description/
 *time:28min
 *solution:
 *easy
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<int> vi;
		vector<vector<int>> res(numRows, vi);

		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j <= i; j++) {
				if (j == 0 || j== i)
					res[i].push_back(1);
				else res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]);
			}
		}

		return res;
	}
};

int main() {
	Solution sol;
}
