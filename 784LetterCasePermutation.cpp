/*https://leetcode.com/problems/letter-case-permutation/description/
 *time:25min
 *solution:backtracking case tog using bit
 *easy
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> letterCasePermutation(string S)  {
		vector<string> res;
		if (S.size() == 0)
			return res;

		lcp(res, S, 0);
		return res;
	}

private:
	void lcp(vector<string>& res, string& S, int index) {
		res.push_back(S);

		if (index >= S.size())
			return;

		for (int i = index; i < S.size(); i++) {
			if (isalpha(S[i])) {
				S[i] ^= 1 << 5;
				lcp(res, S, i + 1);
				S[i] ^= 1 << 5;
			}
		}
	}
};

int main() {
	Solution sol;
	vector<string> res = sol.letterCasePermutation("a1b2");
	for (int i = 0; i < (int)res.size(); i++)
		cout << res[i] << ' ';

	cout << endl;
	return 0;
}
