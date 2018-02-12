/*https://leetcode.com/problems/intersection-of-two-arrays/description/
 *time:18:23min
 *solution:set
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
/*
		int len1 = nums1.size(), len2 = nums2.size();
		if (len1 <= len2) {
			vector<int> n(nums1);
		} else {
			vector<int> n(nums2);
		}
 */
	
		unordered_set<int> temp(nums1.begin(), nums1.end());

		vector<int> res;
		for (size_t i = 0; i < nums2.size(); i++) {
			if (temp.count(nums2[i]) > 0) {
				res.push_back(nums2[i]);
				temp.erase(nums2[i]);
			}
		}

		return res;		
	}
};

int main() {
	vector<int> nums1 = {1, 2, 2, 1};
	vector<int> nums2 = {2, 2};
	Solution sol;
	vector<int> res = sol.intersection(nums1, nums2);
	for (auto i: res) {
		cout << i << ' ';
	}
	cout << endl;
	return 0;
}
