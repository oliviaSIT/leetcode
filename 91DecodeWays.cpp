/*https://leetcode.com/problems/decode-ways/description/
 *time:50min
 *solution: dp
 *medium
 */

class Solution {
public:
	int numDecodings(string& s) {
		int l = s.length();
		if (l == 0) {
			return 0;   // only for this problem, but the ans should be 1
		}

		vector<int> f(l + 1);
		f[0] = 1;

		for (int i = 0; i < l; i++) {
			f[i + 1] = 0;
			if (s[i] != '0') {
				f[i + 1] += f[i];
			}
			if(i >= 1 && (s[i - 1] - '0') * 10 + s[i] - '0' <= 26 && s[i - 1] != '0') {
				f[i + 1] += f[i - 1];
			}	
		}
	
		return f[l];
        }
};
