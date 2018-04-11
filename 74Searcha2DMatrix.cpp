/*https://leetcode.com/problems/search-a-2d-matrix/description/
 *time:21min
 *solution
 *medium
 */

#include <iostream>
#include <vector>

using namespace std;
/*
class Solution {
public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
                if (matrix.size() == 0 || matrix[0].size() == 0)
                        return false;

                int st = 0, ed = matrix.size() - 1, md = st + (ed - st) / 2;
                if (target == matrix[st][0] || target == matrix[ed][0])
                        return true;
            
                while (st < ed) {
                        md = st + (ed - st) / 2;
                        if (matrix[md][0] == target)
                                return true;
                        else if (matrix[md][0] > target)
                                ed = md;
                        else st = md + 1;
                }

                int row = md;
 		cout << "row= " << row << endl;

                st = 0; ed = matrix[row].size() - 1; 
                md = st + (ed - st) / 2;

                if (target == matrix[row][st] || target == matrix[row][ed])
                        return true;

                while (st < ed) {
                        md = st + (ed - st) / 2;
                        if (matrix[row][md] == target)
                                return true;
                        else if (matrix[row][md] > target)
                                ed = md;
                        else st = md + 1;
                }

		cout << matrix[row][md] << endl;
                return matrix[row][md] == target;
        }
};
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), x, y;
        int lo = 0, hi = m*n-1, mid;
        if (hi == 0) return (matrix[0][0] == target);
        while (lo <= hi)
        {
            mid = lo + (hi-lo)/2;
            x = mid / n; y = mid % n;
            if (matrix[x][y] == target)
                return true;
            else if (matrix[x][y] > target)
                hi = mid-1;
            else
                lo = mid+1;
        }
        return false;
    }
};
int main() {
	Solution sol;
	vector<vector<int>> m{{1,3,5,7},{10,11,16,20},{23,30,34,50}};
	cout << sol.searchMatrix(m, 30) << endl;
	return 0;
}
