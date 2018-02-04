/*https://leetcode.com/problems/sqrtx/description/
 *time:20min
*/



#include <iostream>

using namespace std;
/*  time is long
class Solution {
public:
        int mySqrt(int x) {
            int sq = 1;
            while (sq <= x / sq) {  // sq * sq <= x --> overflow
                sq++;
            }
            return  --sq;
        }
};
*/

class Solution {
public:
        int mySqrt(int x) {
		if (x == 0 || x == 1)
			return x;

		int left = 1, right = x / 2;
		while (left + 1 < right) {
			int mid = left + (right - left) / 2;
			if (mid < x / mid) {
				left = mid;
			} else {
				right = mid;
			}
		}

		if (right <= x / right)
			return right;

		return left;
	}	
};
int main() {
	Solution sol;
	int x;
	cout << "Input a non-negative number:" << endl;
	cin >> x;
	cout << sol.mySqrt(x) << endl;
	
	return 0;
}
