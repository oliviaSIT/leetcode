/*https://leetcode.com/problems/largest-number/description/
 *time:
 *solution:First convert numbers to strings. Then sort strings in order like: l=abc,s=de, if abcde > deabc, then l appear first.
 *corner case:a list of 0 should return one 0
 *medium
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
        string largestNumber(vector<int>& nums) {
		vector<string> strs = convertToString(nums);
		sort(strs.begin(), strs.end(), numCompare);
		string res;
		for (string& s: strs) 
			res += s;
		res.erase(0, min(res.find_first_not_of('0'), res.size() - 1));// remove leading 0
		return res;
        }

private:
	vector<string> convertToString(const vector<int>& nums) {
		vector<string> res;
		//201 -> '1','0','2'->'2','0','1'->"201"
		for (int num: nums) {
			vector<char> numInStr;

			if (num == 0) {
				numInStr.push_back('0');
			} else {
				while (num != 0) {
					numInStr.push_back(num % 10 + '0');
					num /= 10;
				}
			}

			reverse(numInStr.begin(), numInStr.end());
			res.push_back(string(numInStr.begin(), numInStr.end()));
		}		
		return res;
	}

	// why static?
	bool static numCompare(const string& larger, const string& smaller) {
		//when a == b return false
		size_t lSize = larger.size(), sSize = smaller.size();
		if (lSize == 0 || sSize == 0)
			return false;
	
		size_t l = 0, s = 0;
		for (size_t i = 0; i < lSize + sSize; i++) {
			char lC = l < lSize ? larger[l] : smaller[l - lSize];
			char sC = s < sSize ? smaller[s] : larger[s - sSize];
			l++;s++;

			if (lC > sC) 
				return true;

			if (lC < sC)
				return false;
		}

		return false;
	}

};

int main() {
	Solution sol;
	vector<int> nums{121, 12, 4};

	cout << sol.largestNumber(nums) << endl;

	return 0;
}
