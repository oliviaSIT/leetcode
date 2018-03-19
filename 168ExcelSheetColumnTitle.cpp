/*https://leetcode.com/problems/excel-sheet-column-title/description/
 *time:31min
 *solution:
 *corner case: 0->Z
 *easy;
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		string res;
		string str = "ZABCDEFGHIJKLMNOPQRSTUVWXY";
		while (n != 0) {
			res.push_back(str[n % 26]);
			n =  (n - 1) / 26;
		}

		reverse(res.begin(), res.end());
		return res;
	}
};

int main() {
	Solution sol;
	cout << sol.convertToTitle(29) << endl;
	return 0;
}
