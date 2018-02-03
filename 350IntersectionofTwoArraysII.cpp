/*
 *https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 * think: 5min copy:15:30min
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        	if (nums1.size() == 0 || nums2.size() == 0) {
			return {};
		}

		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());

		vector<int> res;
		size_t idx1 = 0, idx2 = 0;
		while (idx1 != nums1.size() && idx2 != nums2.size()) {
			if (nums1[idx1] == nums2[idx2]) {
				res.push_back(nums1[idx1]);
				idx1++;
				idx2++;
			}else if (nums1[idx1] < nums2[idx2]) {
				idx1++;
			}else {
				idx2++;
			}
		}
		return res;
		
        }
};

int main() {
	Solution sol;

	vector<int> nums1 = {1, 2, 2, 1};
        vector<int> nums2 = {2, 2};
        for (int &num : sol.intersect(nums1, nums2))
        cout << num << " ";
        cout << endl;
	return 0;
}
