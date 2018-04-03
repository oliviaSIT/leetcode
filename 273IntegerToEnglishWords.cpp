/*https://leetcode.com/problems/integer-to-english-words/description/
 *time:53min
 *solution:
 *hard
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string numberToWords(int num) {
		if (num == 0)
			return "Zero";

		vector<string> str;
		while (num > 0) {
			str.push_back(convert(num % 1000));
			num /= 1000;
		}

		vector<string> units = {"Thousand", "Million", "Billion"};
		string res;

		for (int i = (int)str.size() - 1; i > 0; i--) {
			if (str[i] != "")
				res += str[i] + " " + units[i - 1] + " ";
		}

		res += str[0];

		if (res.back() == ' ')
			res.erase(res.end() - 1);

		return res;
	}

	string convert(int num) {
		int hundred = num / 100, ten = num % 100;

		string res;

		if (hundred > 0) 
			res += oneMap[hundred] + " " + "Hundred" + " ";

		if (ten < 20) 
			res += oneMap[ten];
		else {
			int tenDigit = ten / 10, oneDigit = ten % 10;
			res += tenMap[tenDigit];

			if (oneDigit > 0)
				res += " " + oneMap[oneDigit];
		}

		if (res.back() == ' ')
			res.erase(res.end() - 1);

		return res;
	}

	vector<string> oneMap = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
	vector<string> tenMap = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

};

int main() {
	Solution sol;

	vector<int> testCases = {123, 12345, 1234567, 123000, 1000010, 100000};
	vector<string> results = {"One Hundred Twenty Three", "Twelve Thousand Three Hundred Forty Five", "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
        , "One Hundred Twenty Three Thousand", "One Million Ten", "One Hundred Thousand"};

	for (size_t i = 0; i < testCases.size(); ++i) {
		string r = sol.numberToWords(testCases[i]);
		cout << r;
		if (r != results[i])
			cout << " Fail";
		cout << endl;
	}
	return 0;
}
