/*https://leetcode.com/problems/count-primes/description/
 *time: 20min
*/
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
/*solution1 
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
*/

class Solution {
public:
	int countPrimes(int n) {
		vector<bool> nums(n, true);
		nums[0] = false;
		nums[1] = false;

		int mul = 2;
		while (mul * mul < n) {
			if (nums[mul]) {
				for (int i = mul * mul; i < n; i += mul) {
					nums[i] = false;
				}
			}
			mul++;
		}

		int res = 0;
		for (int i = 2; i < n; i++) {
			if (nums[i]) 
				res++;
		}
		return res;
        }


};

int main() {
	Solution sol;
	cout << sol.countPrimes(3) << endl;
	return 0;
}
