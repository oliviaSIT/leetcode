/*https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *time:64min
 *solution: brute force
 *hard
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		int maxArea = 0;
		for (int i = 0; i<height.size(); i++)
			maxArea = max(maxArea, calRecArea(height, i));
		return maxArea;
	}

	int calRecArea(vector<int> &height, int index) {
		int left = index - 1, right = index + 1;
		while (left >= 0 && height[left] >= height[index])
			left--;
		while (right<height.size() && height[right] >= height[index])
			right++;

		return (right - left - 1)*height[index];
	}
};

int main() {
	vector<int> v{ 2,1,5,6,2,3 };
	Solution sol;
	cout << sol.largestRectangleArea(v) << endl;
	return 0;
}
