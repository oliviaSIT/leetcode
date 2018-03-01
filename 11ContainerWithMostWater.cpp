/*https://leetcode.com/problems/container-with-most-water/description/
 *time:43min
 *solution:greedy 2pointors if one height is longer than the other, no need to move forward
 *medium
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int res = 0, st = 0, ed = height.size() - 1;

		while (st < ed ) {
			res = max(res, min(height[st], height[ed]) * (ed - st));
			
			if (height[st] <= height[ed])	
				st++;
			else ed--;
		}

		return res;
	}
};

int main() {
	Solution sol;
	vector<int> v{1, 3, 4, 7};
	cout << sol.maxArea(v) << endl;
	return 0;
}

