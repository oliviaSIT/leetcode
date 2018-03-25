/*https://leetcode.com/problems/string-to-integer-atoi/description/
 *time:2 hours
 *solution:
 *corner case: overflow return
 *medium
 */

#include <iostream>
#include <string>
#include <cctype>
#include <climits>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		if (str.length() == 0)
			return 0;

		int i = 0, sign = 1;
		while (i < (int)str.length() && isspace(str[i]))
			i++;
                
		if (i == (int)str.length())
			return 0;
        
		if (str[i] == '+') {
			if (i == (int)str.length() - 1 || !isdigit(str[i + 1]))
				return 0;
			else i++;
		}
                                
		if (str[i] == '-') {
			if (i == (int)str.length() - 1 || !isdigit(str[i + 1]))
				return 0;
			else {
				sign = -1;
				i++;
			}
		}
                
		if (!isdigit(str[i]))
			return 0;              

		long res = 0;
		while (i < (int)str.length() && isdigit(str[i])) {
			if (res > INT_MAX / 10 || res == INT_MAX / 10 && str[i] - '0'> INT_MAX % 10)
				return sign == 1 ? INT_MAX : INT_MIN;

			res = res * 10 + (str[i] - '0');
			i++;
		}

		return sign * res;
	}
};


int main() {
	Solution sol;
	cout << sol.myAtoi("1") << endl;
	return 0;
}
