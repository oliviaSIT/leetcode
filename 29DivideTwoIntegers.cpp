/*https://leetcode.com/problems/divide-two-integers/
 *Medium
 *time:53min
 *solution: dividend = 2^k1 * divisor + 2^k2 * divisor......
 */

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
			return INT_MAX;

		int sign = 0;
		if ((dividend < 0) ^ (divisor < 0)) 
			sign = 1;
		
		long long m = labs(dividend);
		long long n = labs(divisor);

		int result = 0;
		while (m >= n) {
			long long temp = n, bit = 1;
			while (m >= (temp << 1)) {
				temp <<= 1;
				bit <<= 1;
			}

			m -= temp;
			result += bit;
		}

		if (sign == 0) {
			return result;
		} else {
			return -result;
		}
	}
};


