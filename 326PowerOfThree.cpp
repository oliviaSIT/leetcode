/*https://leetcode.com/problems/power-of-three/description/
 *time:27min
 *solution: loga(b) = log10(b) / log(a)
 *corner case: round
 *easy
 */

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
	bool isPowerOfThree(int n) {
		if (n < 1)
			return false;

		return pow(3, round(log(n) / log(3))) == n;
	}
};

int main() {
	Solution sol;
	cout << sol.isPowerOfThree(45) << endl;
	return 0;
}
