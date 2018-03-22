/*https://leetcode.com/problems/fraction-to-recurring-decimal/description/
 *time:53min
 *solution
 *medium
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		string res;
		if ( (numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0) )
			res += "-";

		long num = abs(long(numerator));
		long den = abs(long(denominator));
		
		res += to_string(num / den);

		long left = num % den * 10;
		if (left == 0)
			return res;

		vector<char> fractionPart;
		unordered_map<long, size_t> map;
		while (left != 0) {
			if (map.find(left) != map.end())
				return res + "." + constructRepeat(fractionPart, map[left]);
		
			map[left] = fractionPart.size();
			fractionPart.push_back(left / den + '0');
			left = left % den * 10;
		}
		
		return res + "." + constructRepeat(fractionPart, fractionPart.size());
	}

private:
	string constructRepeat(vector<char>& fractionPart, size_t loopIdx) {
		string res = string(fractionPart.begin(), fractionPart.begin() + loopIdx);
		if (loopIdx == fractionPart.size())
			return res;

		res += "(" + string(fractionPart.begin() + loopIdx, fractionPart.end()) + ")";
		return res;
	}
};

int main() {
	Solution sol;
	cout << sol.fractionToDecimal(-1, 2) << endl;
	return 0;
}
