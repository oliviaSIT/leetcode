/*https://leetcode.com/problems/plus-one/description/
 *time:
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
        vector<int> plusOne(vector<int>& digits) {
		digits[digits.size() - 1] += 1;

		
        	for (size_t i =  digits.size() - 1; i > 0; i--) {
			if (digits[i] == 10) {
				digits[i] = 0;
				digits[i - 1] += 1;
			}
		}
		
		if (digits[0] == 10) {
			digits[0] = 0; 
			digits.push_back(digits.back());
			for (int i = digits.size() - 2; i > 0; i--) {
				digits[i] = digits[i - 1];
			}
			digits[0] = 1;
		}		
		
		return digits;
        }
};

int main() {
	Solution sol;
	vector<int> input={9, 9, 9};
	vector<int> output;
	output = sol.plusOne(input);
	for (int i = 0; i < output.size(); i++) {
		cout << output[i] << ' ';
	}
	cout << endl;

	return 0;
}
