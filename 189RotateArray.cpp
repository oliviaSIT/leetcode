/*https://leetcode.com/problems/rotate-array/description/
 *time: 40min
 *corner case: n < k
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
        void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		k = k % n;
		
        	for (int i = 0; i < n - k; i++) {
			nums.push_back(nums[i]);
		}
		
		for (int i = 0; i < n; i++) {
			nums[i] = nums[i + n - k];
		}

		for (int i = 0; i < n - k; i++)
			nums.pop_back();
        }
};

int main() {
	vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
	Solution sol;
	sol.rotate(nums, 3);
	for (int i = 0; i < nums.size(); i++) {
		cout << nums[i] << ' ';
	}
	cout << endl;
	return 0;
}
