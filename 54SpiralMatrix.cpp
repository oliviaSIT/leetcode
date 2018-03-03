/*https://leetcode.com/problems/spiral-matrix/description/
 *time: 51min
 *solution: two border
 *medium
 */

#include <iosream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;

		if (matrix.empty() || matrix[0].empty())
			return res;

		int rowSt = 0, rowEd = matrix.size() - 1;
		int colSt = 0, colEd = matrix[0].size() - 1;

		while (rowSt <= rowEd && colSt <= colEd) {
			for (int j = colSt; j <= colEd; j++) {
				res.push_back(matrix[rowSt][j]);
			}		
			rowSt++;

			for (int i = rowSt; i <= rowEd; i++) {
				res.push_back(matrix[i][colEd]);
			}
			colEd--;

			if (rowSt <= rowEd) {
				for (int j = colEd; j >= colSt; j--)
					res.push_back(matrix[rowEd][j]);
				
				rowEd--;
			}

			if (colSt <= colEd) {
                                for (int i = rowEd; i >= rowSt; i--)
                                        res.push_back(matrix[i][colSt]);

                                colSt++;
                        }
		}

		return res;
	}
};
