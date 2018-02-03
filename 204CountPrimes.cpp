/*https://leetcode.com/problems/count-primes/description/
 *time: 20min
*/

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
	int countPrimes(int n) {
		int count = 0;
		for (int i = 1; i < n; i++) {
			if (isPrimes(i))
				count++;
		}
		return count;
	}

	bool isPrimes(int x) {
		if (x == 1)
			return false;

		if (x == 2)
			return true;

		for (int i = 2; i <= sqrt(x); i++) {
			if (x % i == 0) 
				return false;
		}
		return true;
	}
};

int main() {
	Solution sol;
	cout << sol.countPrimes(3) << endl;
	return 0;
}
