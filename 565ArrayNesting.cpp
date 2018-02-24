/*https://leetcode.com/problems/array-nesting/description/
 *time:43min 
 *solution:circle + marka[k] = -1;
 *medium
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int arrayNesting(vector<int>& nums) {
		int res = 0;
		for (int i = 0; i < (int)nums.size(); i++) {
			if (nums[i] != -1) {
				int s = nums[i];
				nums[i] = -1;
				int count = 1;
				while (s != i) {
					int temp = nums[s];
					nums[s] = -1;
					s = temp;
					count++;
				}

				res = max(res, count);
			}
		}

		return res;

	}
};

int main() {
	Solution sol;
	vector<int> v{5, 4, 0, 3, 1, 6, 2};
	cout << sol.arrayNesting(v) << endl;
	return 0;
}
