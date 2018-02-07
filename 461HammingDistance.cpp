/*https://leetcode.com/problems/hamming-distance/description/
 *time:15min
 *solution:bit manipulation
 */

#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
        int hammingDistance(int x, int y) {
        	unsigned z = x ^ y;
		bitset<32> bit(z);
		
		int res = 0;
                for (size_t i = 0; i < 32; i++) {
                    if (bit.test(i))
                        res++;
                }
                
                return res;
        }
};

int main() {
	Solution sol;
	cout << sol.hammingDistance(1, 4) << endl;
	return 0;
}
