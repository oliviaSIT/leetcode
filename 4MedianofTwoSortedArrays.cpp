/*https://leetcode.com/problems/median-of-two-sorted-arrays/description
 *time:
 *solution:use binary search to find i, j, ensure: i + j = (m + n + 1) / 2 && A[i - 1] <= B[j] && B[j - 1] <= A[i]
 *corner case: i = 0,m, j = 0,n
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > nums2.size())
			return findMedianSortedArrays(nums2, nums1);

		int m = nums1.size(), n = nums2.size();

		if (m == 0) {
			if (n % 2 == 1)
				return nums2[n / 2];
			else return (nums2[n / 2 - 1] + nums2[n / 2]) / 2.;
		}

		int st = 0, ed = m;
		int i, j, median1, median2;
		while (st <= ed) {
			i = st + (ed - st) / 2;
			j = (m + n + 1) / 2 - i;

			if (i < m && nums2[j-1] > nums1[i]) 
				st = i + 1;
			else if (j < n && nums2[j] < nums1[i - 1])
				ed = i - 1;
			else {
				if (i == 0) 
					median1 = nums2[j - 1];
				else if (j == 0) 
					median1 = nums1[i - 1];
				else median1 = max(nums1[i - 1], nums2[j - 1]);
					break;
			}	
		}	

		if ((m + n) % 2 == 1) 
			return median1;
    
		if (i == m) 
			median2 = nums2[j];
		else if (j == n) 
			median2 = nums1[i];
    		else median2 = min(nums1[i], nums2[j]);
			
		return (median1 + median2) / 2.;
	}
};

int main() {
	Solution sol;
	vector<int> nums1{1, 1, 4};
	vector<int> nums2{2,3};
	cout << sol.findMedianSortedArrays(nums1, nums2) << endl; 
	return 0;
}
