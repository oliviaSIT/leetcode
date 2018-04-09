/*https://leetcode.com/problems/zigzag-conversion/description/
 *time:51min
 *solution:string in circle 2 * rows - 2, if not first or last line , need add one character
 *corner case: numRows = 1
 *medium
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (s.size() == 0 || numRows < 2)
			return s;

		string res = "";

		int len = 2 * numRows - 2;
		for (int i = 0; i < numRows; i++) {
			for (int j = i; j < (int)s.size(); j += len) {
				res += s[j];

				if (i > 0 && i < numRows - 1) {
					int t = j + len - 2 * i;
					if (t < len)
						res += s[t];
				}
			}
		}

		return res;
	}
};

int main() {
	Solution sol;
	cout << sol.convert("PAYPALISHIRING", 3) << endl;
	return 0;
}
