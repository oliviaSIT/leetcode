/*https://leetcode.com/problems/valid-number/description/
 *time:
 *solution:
 *hard:should include all cases
 */

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
private:
	string trim(const string& s) {
		size_t st = s.find_first_not_of(' ');// find the start position
		if (st == string::npos)
			return s;

		size_t ed = s.find_last_not_of(' ');
		return s.substr(st, ed - st + 1);
	}

	bool containsInvalidChar(const string& s) {
		int len = s.length();
		int ePos = len, dotPos = len;
		for (int i = 0; i < len; ++i) {
			char c = s[i];
//sign can only show at beginning or after Exp
			if (c == '+' || c == '-') {
				if (i != 0 && i != ePos + 1) 
					return true;
			} else if (c == 'e' || c == 'E') {
				// Exp can only show once
				if (ePos != len)
					return true;

				ePos = i;
			} else if (c == '.') {
				// dot can only show once and before Exp
				if (dotPos != len || i > ePos)
					return true;
					
				dotPos = i;
			} else if (!isdigit(c)) {
				return true;
			}
		}

		return false;
	}

	vector<string> split(const string& s, string delims) {
		vector<string> tokens;
		
		for (const char& c : delims) {
			size_t p = s.find(c);
			if (p != string::npos) {
				tokens.push_back(s.substr(0, p));
				if (p == s.length() - 1) {
					tokens.push_back("");
				} else {
					tokens.push_back(s.substr(p + 1, s.length() - p - 1));
				}
			}
		}

		if (tokens.size() == 0)
			tokens.push_back(s);

		return tokens;
	}
	
	bool isInteger(const string& s) {
		if (s.find('.') != string::npos || s.length() == 0)
			return false;

		size_t i = 0;
		if (s[0] == '+' || s[0] == '-')
			i++;
		return s.length() > i;
	}

	bool isValidDicimal(const string& s) {
		// cannot only has a dot
		if (s.length() == 0)
			return false;

		size_t i = 0;
		if (s[0] == '+' || s[0] == '-')
			i++;

		if (s.length() == i)
			return false;

		return !(s[i] == '.' && s.length() == i + 1);
	}

public:
	bool isNumber(string s) {
		string str = trim(s);
		if ( str == "" || containsInvalidChar(str) )
			return false;

		vector<string> breakByExp = split(str, "eE");
		if (breakByExp.size() == 2) {
			if (!isInteger(breakByExp[1]))
				return false;
		}
		
		if (!isValidDicimal(breakByExp[0]))
			return false;

		return true;
	}		
};

int main() {
	Solution sol;
	cout << sol.isNumber("21") << endl;
	return 0;
}
