/*https://leetcode.com/problems/spiral-matrix-ii/description/
 *time:
 *solution:
 *medium
 */

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        		vector<int> v(n, 0);
                vector<vector<int>> res(n, v); 

    	    	int rowSt = 0, rowEd = n - 1;
	    	    int colSt = 0, colEd = n - 1;
                
                int value = 1;
		        while (value <= n * n) {
			        for (int j = colSt; j <= colEd; j++) {
				        res[rowSt][j] = value;
                        value++;
			        }		
			        rowSt++;

			        for (int i = rowSt; i <= rowEd; i++) {
				        res[i][colEd] = value;
                        value++;
			        }
			        colEd--;

			        if (value <= n * n) {
				        for (int j = colEd; j >= colSt; j--) {
					        res[rowEd][j] = value;
                            value++;
                        }
				        rowEd--;
			        }

			        if (value <= n * n) {
                        for (int i = rowEd; i >= rowSt; i--) {
                            res[i][colSt] = value;
                            value++;
                        }
                        colSt++;
                    }
		}

		return res;
    }
};
