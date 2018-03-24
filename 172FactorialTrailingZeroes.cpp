/*https://leetcode.com/problems/factorial-trailing-zeroes/description/
 *time: 24min
 *solution: 2*5 = 10, 25 offers 2 "5"
 *easy
 */

#include <iostream>

using namespace std;

class Solution {
public:
	int trailingZeroes(int n) {
		int count = 0;
		for (long long i = 5; n / i > 0; i *= 5 )
			count++;

		return count;
	}
};

int main() {
	Solution sol;
	cout << sol.trailingZeroes(10) << endl;
	return 0;
}
