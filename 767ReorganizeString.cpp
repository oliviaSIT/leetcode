/*https://leetcode.com/problems/reorganize-string/description/
 *time:31:49
 *solution:sort the string,Next, let i = 0 at the beginning, j = (n-1)/2+1 in the middle,build the answer by appending s[i++] and s[j++] sequentially.
 *medium
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	string reorganizeString(string S) {
		//build a frequency table of 26 alphabits
		vector<int> charFre(26);
		int n = S.size();
		for (char c: S)
			++charFre[c - 'a'];
		//count the number of char in string S
		vector<pair<int, char>> charCounts;
		for (int i = 0; i < 26; i++) {
			if (charFre[i] > (n + 1) / 2) return "";

			if (charFre[i]) charCounts.push_back({charFre[i], i + 'a'});
		}

		sort(charCounts.rbegin(), charCounts.rend());//aaaabbcc
		
		string strSorted;
		for (auto& p: charCounts) 
			strSorted += string(p.first, p.second);

		string res;
		for (int i = 0, j = (n - 1) / 2 + 1; i < (n - 1) / 2 + 1 || j < n; i++, j++) {
			res += strSorted[i];
			if (j < n) res += strSorted[j];
		}

		return res;
	}
};

int main() {
	string S = "aaabbcc";
	Solution sol;
	cout << sol.reorganizeString(S) << endl;
	return 0;
}
