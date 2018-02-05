/*https://leetcode.com/problems/single-number/description/
  time: 30min
  sol: a ^ a = 0; a ^ b = 1;
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int result = 0;
		
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			result ^= nums[i];
		}
		
		return result; 
	}
};

int main() {
	Solution sol;
	vector<int> a{1, 1, 2, 3, 3};
	cout << sol.singleNumber(a) << endl;
	return 0;
}
