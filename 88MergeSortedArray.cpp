/*https://leetcode.com/probleims/merge-sorted-array/description/
 *time:5min + 5min
 *solution:from m + n - 1 to 0
 *easy
 */
/*
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        vector<int> temp;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j])
                temp.push_back(nums1[i++]);
            else temp.push_back(nums2[j++]);            
        }
        
        while (i < m)
            temp.push_back(nums1[i++]);
        
        while (j < n)
            temp.push_back(nums2[j++]);
        
        nums1 = temp;
        return;
    }
};
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int ed1 = m - 1, ed2 = n - 1, ed = m + n - 1;
		while (ed1 >= 0 && ed2 >= 0) {
			if (nums1[ed1] > nums2[ed2])
				nums1[ed] = nums1[ed1--];
			else nums1[ed] = nums2[ed2--];

			ed--;
		}
		
		while (ed2 >= 0) {
			nums1[ed] = nums2[ed2--];
			ed--;
		}
	}
};
