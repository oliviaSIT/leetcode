/*https://leetcode.com/problems/swap-adjacent-in-lr-string/description
 *time:53min
 *solution: LR should have the same order in start and end, L in start need to be ahead of the position in end, R in start need to be behind of the position in end
 *medium
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool canTransform(string start, string end) {
		if (start.length() != end.length())
			return false;

		int i = 0, j = 0, n = start.length();
		while (j < n && i < n) {
			while (i < n && start[i] == 'x')
				i++;

			while (j < n && end[j] == 'x')
				j++;

			if (i == n && j == n)
				break;

			if (i == n || j == n || start[i] != end [j])
				return false;

			if (start[i] == 'R' && i > j)
				return false;

			else if (start[i] == 'L' && i < j)
				return false;

			i++;
			j++;
		}

		return true;
	}
};

int main() {
	Solution sol;
	cout << sol.canTransform("RxxLRxRxL", "xRLxRRLx") << endl;
	return 0;
}
