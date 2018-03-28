/*https://leetcode.com/problems/permutation-sequence/description/
 *time:
 *solution:DFS
 *medium
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		string res;
		if (k <= 0)
			return res;

		vector<int> num(n, 0);
		for (int i = 0; i < n; i++) 
			num[i] = i + 1;

		vector<int> fac(n - 1, 1);
		for (int i = 1; i < n; i++)
			fac[i] = fac[i - 1] * (i + 1);

		getPermutation(k - 1, num, num.size() - 1, fac, res);
		return res;
	}

	void getPermutation(int k, vector<int> num, int last, vector<int> fac, string& res) {
		if (last == 0) {
			res += (num[0] + '0');
			return;
		}

		int mul = k / fac[last - 1];
		int mod = k % fac[last - 1];
		res += (num[mul] + '0');
		for (int i = mul; i < last; i++) {
			num[i] = num[i + 1];
		} 

		getPermutation(mod, num, last - 1, fac, res);
	}
};

int main() {
	Solution sol;

	for (int i = 1; i <= 6; i++)
	cout << sol.getPermutation(3, i) << endl;

	return 0;
}
