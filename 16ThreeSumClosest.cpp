#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int diff = INT_MAX;

		for (int i = 0; i < nums.size() - 2; i++) {
			int st = i + 1, ed = nums.size() - 1;
			while (st < ed) {
				int sum = nums[i] + nums[st] + nums[ed];
				if (sum == target)
					return sum;

				if (abs(sum - target) < abs(diff)) 
					diff = sum - target;

				if (sum < target)
					st++;
				else ed--;
			}
		}
		return target + diff;
	}
};

int main() {
	Solution sol;
	vector<int> v{-1, 2, 1, -4};
	int target = 1;
	cout << sol.threeSumClosest(v, target) << endl;

	return 0;

}
