/*https://leetcode.com/problems/generate-parentheses/description/
 *time:
 *solution:
 *medium
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		if (n <= 0)
			return res;

		string cur;
		help(res, cur, n, 0, 0);
		return res;
	}

private:
	void help(vector<string>& res, string cur, int n, int l, int r) {
		if (r == n) {
			res.push_back(cur);
			return;
		}
		
		else if (l == n) {
			cur += ')';
			help(res, cur, n, l, r + 1);
		}
		
		else {
			if (l > r) 
				help(res, cur + ')', n, l, r + 1);

			help(res, cur + '(', n, l + 1, r);
		}
	}
};

int main() {
	Solution sol;
	vector<string> res = sol.generateParenthesis(3);
	for (int i = 0; i < (int)res.size(); i++)
		cout << res[i] << endl;

	return 0;
}
