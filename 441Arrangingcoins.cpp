/*https://leetcode.com/problems/arranging-coins/description/
 *time:21min
 *easy
 *solution: binary search
 */

#include <iostream>

using namespace std;

class Solution {
public:
	int arrangeCoins(int n) {
		long st = 0, ed = n;
		while (st + 1 < ed) {
			long mid = st + (ed - st) / 2;
			long sum = (1 + mid) * mid / 2;
			if (sum > (long)n)
				ed = mid;
			else
				st = mid;
		}

		if ((1 + ed) * ed / 2 <= n)
			return ed;
		return st;
	}
};

int main() {
	Solution sol;
	int a = 3, b = 5, c = 8;
	cout << sol.arrangeCoins(a) << ' ' << sol.arrangeCoins(b) << ' ' << sol.arrangeCoins(c) << endl;
	return 0;
}
