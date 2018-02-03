/*https://leetcode.com/problems/reverse-string/description/
* time:15min
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;
/* char -> string?
class Solution {
public:
	string reverseString(string s) {
        	vector<char> reverse;
		for(size_t i = s.length(); i >= 0; i--) {
			reverse.push_back(s[i]);
		}

		string rs(reverse[0]);
		for(int i = 1; i < s.length(); i++) {
			rs = rs + (string)reverse[i];
		}
		return rs;
	}
};
*/

class Solution {
public:
        string reverseString(string s) {
		int i = 0, j = s.length() - 1;
		while  (i < j) {
			swap(s[i], s[j]);
			i++;
			j--;
		}
		return s;
	}
};


int main() {
        Solution sol;
        cout << sol.reverseString("hello") << endl;

        return 0;
}
