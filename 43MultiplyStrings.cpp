/*https://leetcode.com/problems/multiply-strings/description/
 *time: 43min
 *solution:
 *medium
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
        
		unsigned int l1 = num1.size(), l2 = num2.size();
		if (l1 == 0||l2 == 0)
			return "0";
            
		if (num1 == "0" || num2 == "0")
			return "0";
        
		vector<int> v(l1 + l2, 0);
 
		for (unsigned int i = 0; i < l1; i++) {
			int carry=0;
			int n1 = (int)(num1[l1 - i - 1] - '0');

			for (unsigned int j = 0;j < l2; j++) {
				int n2 = (num2[l2 - j - 1] - '0');
                
				int sum = n1 * n2 + v[i + j] + carry;
				carry = sum / 10;
				v[i + j] = sum % 10;
			}

			if (carry > 0)
				v[i + l2] += carry;

		}

		int start = l1 + l2 - 1;
		while (v[start] == 0) 
			start--;
      
		string s = "";
		for (int i = start;i >= 0;i--)
			s += (char)(v[i] + '0');
        
		return s;
	}
};

int main() {
	Solution sol;
	cout << sol.multiply("12", "11") << endl
	return 0;
}
