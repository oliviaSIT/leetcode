/*https://leetcode.com/problems/power-of-two/description/
 *time:14min
 *solution:bit
 *easy
 */

class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n <= 0)
			return false;
		return (n & (n - 1)) == 0;
	}
};
