/*
 *https://leetcode.com/problems/length-of-last-word/discuss/21892/7-lines-4ms-C++-Solution
 * time: 30min 
 * corner case: "a "
*/
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int tail = s.length() - 1;
		while (tail >= 0 && s[tail] == ' ') tail--;
		int len = 0;
		while (s[tail] != ' ' && tail >= 0) {
			tail--;
			len++;
		}	
		return len;
        }
};

int main() {
	string s = "a b ";
	Solution sol;
	cout << sol.lengthOfLastWord(s) << endl;
	return 0;
}
