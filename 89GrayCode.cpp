/*https://leetcode.com/problems/gray-code/description/
 *time:(1)45min + (2)23min
 *solution:
 *medium
 */

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		bitset<32> bits;
		vector<int> res;
		
		help(bits, res, n);

		return res;
	}

	void help(bitset<32>& bits, vector<int>& res, int n) {
		if (n == 0) {
			cout << bits << endl;
			res.push_back(bits.to_ulong());
		} else {
			help(bits, res, n - 1);
			bits.flip(n - 1);
			help(bits, res, n - 1);
		}
	}
};
/*
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> res;
		res.push_back(0);

		if (n <= 0)
			return res;

		res.push_back(1);
		int bit = 1, add = 1;
		while (bit < n) {
			add *= 2;
			for (int i = add - 1; i >= 0; i--) {
				res.push_back(res[i] + add);
			}

			bit++;	
		}

		return res;
	}
};
*/
int main() {
	Solution sol;
	vector<int> res = sol.grayCode(3);
//	for (int i = 0; i < (int)res.size(); i++)
//		cout << res[i] << ' ';
//
//	cout << endl;
	return 0;
}
