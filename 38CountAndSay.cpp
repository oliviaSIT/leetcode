/*https://leetcode.com/problems/count-and-say/description
 *time:23min
 *soluton:
 *easy
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		if (n == 0)
			return "";

		string res = "1";

		for (int i = 0; i < n; i++) {
			string current = "";
			for (int j = 0; j < res.size(); j++) {
				int count = 1;
				while ((j < res.size() - 1) && (res[j] == res[j + 1])) {
					count++;
					j++;
				}

				current += to_string(count) + res[j];
			}
			
			res = current;
		}
		
		return res;
	}
};

int main() {
	Solution sol;
	cout << sol.countAndSay(5) << endl;
	return 0;
}
