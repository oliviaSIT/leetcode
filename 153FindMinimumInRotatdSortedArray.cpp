/*https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description 
 *time: 5min + 22min
 *medium
 *soluion: binary search
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int st = 0, ed = nums.size();
		
		while (st < ed) {
                	if (nums[st] < nums[ed])
        	                return nums[st];

			int md = st + (ed - st) / 2;
			if (nums[md] < nums[ed])
				ed = md;
			else st = md + 1;// st = md is not right
		}
		return nums[st];
	}
};

class Solution {
public:
        int findMin(vector<int>& nums) {
		if (nums[0] < nums[nums.size()]) 
			return nums[0];

		for (int i = 1; i < (int)nums.size(); i++) {
			if (nums[i - 1] > nums[i])
				return nums[i];
		}
	}
};
