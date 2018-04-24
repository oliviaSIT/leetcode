/*https://leetcode.com/problems/ugly-number-ii/description/
 *time:32min
 *solution: if k is an ugly number, k * 2, k * 3, k * 5 are ugly numbers
 *medium
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> uglys(1, 1);
		int p2 = 0, p3 = 0, p5 = 0; 

		while (uglys.size() < n) { 
			int ugly2 = uglys[p2] * 2, ugly3 = uglys[p3] * 3, ugly5 = uglys[p5] * 5;

		//merge sort
		int min_v = min(ugly2, min(ugly3, ugly5));
		if (min_v == ugly2) 
			++p2;

		if (min_v == ugly3)
                        ++p3;

		if (min_v == ugly5)
                        ++p5;

		if(min_v != uglys.back())
			uglys.push_back(min_v);
		}

		return uglys[n - 1];
	}	
};

int main() {
	Solution sol;
	cout << sol.nthUglyNumber(10) << endl;
	return 0;
}
