/* https://leetcode.com/problems/valid-palindrome/description/
 * time: 25min
 * solution: 2 pointers
 */

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
        bool isPalindrome(string s) {
        	vector<char> str;
                for (int i = 0; i < s.length(); i++) {
                        if (isalnum(s[i]))
                                str.push_back(s[i]);
                }

                for (int i = 0, j = str.size() - 1; i < j; i++, j--) {
                        if (isdigit(str[i]) ^ isdigit(str[j])) {
                            return false;
                        } else if (isdigit(str[i]) && isdigit(str[j]) && str[i] != str[j]) {
                            return false;
                        } else if (isalpha(str[i]) && isalpha(str[j]) && toupper(str[i]) != toupper(str[j])) {
                            return false;
                        }
                }

                return true;		
        }
};

int main() {
	Solution sol;
	string s;
	cin >> s;
	cout << sol.isPalindrome(s) << endl;
	return 0;
}
