/*https://leetcode.com/problems/reshape-the-matrix/description
 *time:23min
 *solution:
 *easy
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int m = nums.size(), n = nums[0].size();
		if (m * n != r * c) 
			return nums;

		vector<vector<int>> res(r, vector<int>(c, 0));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int k = i * n + j;
				res[k / c][k % c] = nums[i][j];
			}
		}

		return res;
	}

	void print(vector<vector<int>>& nums) {
		int m = nums.size(), n = nums[0].size();
		for (int i = 0; i < m; i++) {
                        for (int j = 0; j < n; j++) {
				cout << nums[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << endl;
	}
};

int main() {
	Solution sol;
	vector<vector<int>> nums{{1, 2}, {3, 4}};
	sol.print(sol. matrixReshape(nums, 1, 4));
	return 0;
}

