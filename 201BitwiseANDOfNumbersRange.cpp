/*https://leetcode.com/problems/bitwise-and-of-numbers-range/description/
 *time:25min
 *solution:对于一个连续的数字序列，两个相邻的两个数最后一位肯定是不一样的，那么只要m!=n,那么最后一位肯定是0，那么我们就看从哪一位开始m==n即可。
 *medium
 */

#include <iostream>

using namespace std;

class Solution {
public:

	int rangeBitwiseAnd(int m, int n) {
		int offset = 0;
		while (m && n) {
			if (m == n)
				return m << offset;
			
			m >>= 1;
			n >>= 1;
			offset++;
		}

		return 0;
	}
};

int main() {
	Solution sol;
	cout << sol.rangeBitwiseAnd(5, 7) << endl;

	return 0;
}
