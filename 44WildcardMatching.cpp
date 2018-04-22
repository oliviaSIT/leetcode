/*https://leetcode.com/problems/wildcard-matching/description/
 *time:57min
 *solution:dp, similar as 正则表达式
 *hard
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		vector<bool> v(p.size() + 1, false);
		vector<vector<bool>> match(s.size() + 1, v);
		match[0][0] = true;

		for (int p1 = 1; pi <= (int)p.length(); pi++) {
			if (p[pi - 1] == '*')
				match[0][pi] = match[0][pi - 1];
		}
		
		for (int si = 1; si <= (int)s.length(); si++) {
			for (int pi = 1; pi <= (int)p.length(); pi++) {
				if (s[si - 1] == p[pi - 1] || p[pi - 1] == '?')
					match[si][pi] = match[si - 1][pi - 1];
				else if (p[pi - 1] == '*') 
					match[si][pi] = match[si - 1][pi] || match[si][pi - 1];
			}
		}

		return match[s.length()][p.length()];	
	}
};

int main() {
	Solution sol;
	cout << sol.isMatch("aa", "*") << endl;
	return 0;
}
