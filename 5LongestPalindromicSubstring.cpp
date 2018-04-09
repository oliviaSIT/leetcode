/*https://leetcode.com/problems/longest-palindromic-substring/description/
 *time: 59min
 *solution:DP
 *medium
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int l = s.size();
		vector<bool> temp(l, false);
		vector<vector<bool>> isP(l, temp);

		for (int i = 0; i < l - 1; i++) {
			isP[i][i] = true;
			isP[i][i + 1] = (s[i] == s[i + 1]);
		}

		isP[l - 1][l - 1] = true;

		for (int j = 2; j < l; j++) {
			for (int i = 0; i < j - 1; i++) {
				isP[i][j] = (s[i] == s[j] && isP[i + 1][j - 1]);
			}
		}

		int left = 0, right = 0, max = 0;
		for (int i = 0; i < l; i++) {
			for (int j = i; j < l; j++) {
				if (isP[i][j] && j - i > max) {
					max = j - i;
					left = i;
					right = j;
				}
			}
		}

		return s.substr(left, max + 1);
	}
};

int main() {
	Solution sol;
	cout << sol.longestPalindrome("babad") << endl;
	return 0;
}
