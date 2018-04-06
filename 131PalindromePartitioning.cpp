/*https://leetcode.com/problems/palindrome-partitioning/description/
 *time:
 *solution:
 *medium
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<string> pre;
		vector<vector<string>> res;
		partition(s, 0, pre, res);
		return res;
	}

	void partition(string s, int pos, vector<string> pre, vector<vector<string>> res) {
		if (pos == s.size())
			return;

		partition(s, pos + 1, pre, res);
		
		if (!isPalindrome(s, pos))
			return;

		vector<string> addition = pre;
		addition.push_back(s.substr(0, pos + 1));
		if (pos == s.length() - 1) {
			res.push_back(addition);
			return;
		}

		partition(s.substr(pos + 1), 0, addition, res);
	}

	bool isPalindrome(string s, int end) {
		int start = 0;
		while (start < end) {
			if (s[start] != s[end]) 
				return false;
				
			start++;
			end--;
		}

		return true;
	}
};
