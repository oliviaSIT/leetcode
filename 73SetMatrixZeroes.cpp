/*https://leetcode.com/problems/set-matrix-zeroes/description/
 *time:43min
 *solution: if the number = 0, let the left and up be 0
 *corner case: the left or the up has already been 0
 *medium
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		if (matrix.size() == 0 || matrix[0].size() == 0)
			return;
		
		bool left = false;
		for (int i = 0; i <(int)matrix.size(); i++) {
			if (matrix[i][0] == 0)
				left = true;
		}

		bool up = false;
                for (int j = 0; j <(int)matrix[0].size(); j++) {
                        if (matrix[0][j] == 0)
                                up = true;
                }

		for (int i = 1; i < (int)matrix.size(); i++) {
			for (int j = 1; j < (int)matrix[i].size(); j++) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}

		for (int i = 1; i < (int)matrix.size(); i++) {
                        for (int j = 1; j < (int)matrix[i].size(); j++) {
                                if (matrix[i][0] == 0 || matrix[0][j] == 0) 
                                        matrix[i][j] = 0;
                        }
                }

		if (left == true) {
			for (int i = 0; (int)i < matrix.size(); i++)
				matrix[i][0] = 0;
		}

		if (up == true) {
                        for (int j = 0; (int)j < matrix[0].size(); j++)
                                matrix[0][j] = 0;
                }

	}
};

/* if the size of the matrix is larger than 64*64, this solution is wrong
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unsigned long long m = 0, n = 0;
        for (int i = 0; i < (int)matrix.size(); i++) {
            for (int j = 0; j < (int)matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    m |= (1 << i);
                    n |= (1 << j);
                }
            }
        }
        
        for (int i = 0; i < (int)matrix.size(); i++) {
            unsigned long long b = m & (1 << i);
            if (b == (1 << i)) {
                for (int j = 0; j < (int)matrix[i].size(); j++)
                    matrix[i][j] = 0;
            }
        }
        
        for (int j = 0; j < (int)matrix[0].size(); j++) {
            unsigned long long b = n & (1 << j);
            if (b == (1 << j)) {
                for (int i = 0; i < (int)matrix.size(); i++)
                    matrix[i][j] = 0;
            }
        }
    }
};
*/

int main() {
	vector<vector<int>> v{{1, 2, 3}, {4, 0, 1}, {1, 1, 5}};
	Solution sol;
	sol.setZeroes(v);
	for (int i = 0; i < (int)v.size(); i++) {
		for (int j = 0; j < (int)v[i].size(); j++)
			cout << v[i][j] << ' ';

		cout << endl;
	}

	return 0;
}
