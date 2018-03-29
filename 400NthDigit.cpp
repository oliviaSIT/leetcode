/*https://leetcode.com/problems/nth-digit/description/
 *time:15min
 *solution:
 *easy
 */

#include <iostream>

using namespace std;

class Solution {
public:
	int findNthDigit(int n) {
		long base = 9, digits = 1;
		while (n - base * digits > 0) {
			n = n - base * digits;
			base *= 10;
			digits++;
		}

		int index = n % digits;
		if (index == 0)
			index = digits;

		long num = 1;
		for (int i = 1; i < digits; i++)
			num *= 10;

		if (index == digits) {
			num += n / digits - 1;
		} else {
			num += n / digits;
		}

		for (int i = index; i < digits; i++)
			num /= 10;

		return num % 10;
	}
};

int main() {
	Solution sol;
	cout << sol.findNthDigit(11) << endl;
	return 0;
}
