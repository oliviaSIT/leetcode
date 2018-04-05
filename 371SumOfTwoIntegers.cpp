/*
 *time:15min
 *easy
 */

#include <iostream>

using namespace std;

class Solution {
public:
	int getSum(int a, int b) {
		int sum = a;

		while (b != 0) {
			sum = a ^ b;
			b = (a & b) << 1; //carry
			a = sum;
		}

		return sum;
	}
};

int main() {
	Solution sol;
	cout << sol.getSum(1, 2) << endl;
	return 0;
}
