/*https://leetcode.com/problems/1-bit-and-2-bit-characters/discription
 *time:16min
 *solution:
 *easy
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isOneBitCharacter(vector<int>& b) {
		bool bit;

		int i = 0;
		while (i < (int)b.size()) {
			if (b[i] == 1) {
				bit = 0;
				i += 2;
			} else {
				bit = 1;
				i++;
			}
		}

		return bit;
	}
};

int main() {
	Solution sol;
	vector<int> b{1, 1, 1, 0};
	cout << sol.isOneBitCharacter(b) << endl;
	return 0;
}
