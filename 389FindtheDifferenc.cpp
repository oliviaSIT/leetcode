/*https://leetcode.com/problems/find-the-difference/description/
 *time:20min
 *solution:hash table
 *easy
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	char findTheDifference(string s, string t) {
		unordered_map<char, int> map;
		for (char &c : s) {
			map[c]++;
		}

		for (char &c : t) {
			map[c]--;
			if (map[c] < 0)
				return c;
		}

		return '0';
	}
};

int main() {
	string s = "abcde", t = "abcdde";
	Solution sol;
	cout << sol.findTheDifference(s, t) << endl;
	return 0;
}
