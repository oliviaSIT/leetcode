/*https://leetcode.com/problems/integer-to-roman/description/
 *time:57min
 *solution:
 *medium
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		string res;
		
		int t = num / 1000;
		for (int i = 0; i < t; i++) 
			 res += 'M';
	
		num = num - 1000 * t;

		t = num / 100;
		if (t == 9)
			res += "CM";

		if (t == 5)
			res += 'D';

		if (t == 4)
			res += "CD";

		if (t < 9 && t > 5) {
			res += 'D';
			for (int i = 5; i < t; i++) 
				res += 'C';			
		}  

		if (t < 4) {
			for (int i = 0; i < t; i++)
                                res += 'C';
		}

		num = num - 100 * t;

		t = num / 10;
		if (t == 9)
                        res += "XC";

                if (t == 5)
                        res += 'L';

                if (t == 4)
                        res += "XL";

                if (t < 9 && t > 5) {
                        res += 'L';
                        for (int i = 5; i < t; i++)
                                res += 'X';
                } 
		
		if (t < 4) {
                        for (int i = 0; i < t; i++)
                                res += 'X';
                }

		num = num - 10 * t;

		t = num;
		if (t == 9)
                        res += "IX";

                if (t == 5)
                        res += 'V';

                if (t == 4)
                        res += "IV";

                if (t < 9 && t > 5) {
                        res += 'V';
                        for (int i = 5; i < t; i++)
                                res += 'I';
                } 

		if (t < 4) {
                        for (int i = 0; i < t; i++)
                                res += 'I';
                }

		return res;
	}		
};

int main() {
	Solution sol;
	cout << sol.intToRoman(9) << endl;
	return 0;
}
