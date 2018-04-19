/*https://leetcode.com/problems/minimum-size-subarray-sum/description/
 *time:49min
 *solution:
 *medium
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int n = nums.size();
		if (n == 0) 
			return 0;
        
		int left = 0, right = 0, total = 0, ans = n + 1;
		while (right < n ) {
			while (right < n && total < s) 
				total += nums[right++];

			if (total < s) 
				break;
            
			while (left < right && total >= s) 
				total -= nums[left++];

			ans = min(ans, right - left + 1);
		}
        
		if (ans == n + 1) 
			return 0;
		else return ans;
	}
};

int main() {
	Solution sol;
	cout << sol.minSubArrayLen(7, {2,3,1,2,4,3}) << endl;
	return 0;
}
