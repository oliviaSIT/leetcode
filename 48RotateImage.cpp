/*https://leetcode.com/problems/rotate-image/description/
 *time: 54min
 *solution: save the index in one temp var
 *medium
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		if (matrix.size() < 2)
			return;

		int n = matrix.size();
		for (int i = 0; i < n / 2; i++) {
			for (int j = i; j < n - i -1; j++) {
				int x = i;
				int y = j;
				int temp = matrix[i][j];

				for (int c = 0; c < 3; c++) {
					matrix[x][y] = matrix[n - 1 - y][x];
					int t = x;
					x = n - 1 - y;
					y = t;
				}
				matrix[x][y] = temp;
			}
		}
	}
};
