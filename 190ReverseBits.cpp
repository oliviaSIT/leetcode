/*https://leetcode.com/problems/reverse-bits/description/
 *time:20min 
 *solution1's compile time limit exceeded
*/

#include <iostream>
#include <algorithm>
#include <bitset>
#include <cstdint>

using namespace std;

/*Solution1 Compile time limit exceeded
class Solution {
public:
        uint32_t reverseBits(uint32_t n) {
        	bitset<32> bit(n);
		for (int i = 0, j = bit.size() - 1; i < j; i++, j--) {
			bool temp = bit[i];
			bit[i] = bit[j];
			bit[j] = temp;
		}
		
		return bit.to_ulong();
        }
};
*/



int main() {
	Solution sol;
	uint32_t n;
	cin >> n;
	cout << sol.reverseBits(n) << endl;
	
	return 0;
}
