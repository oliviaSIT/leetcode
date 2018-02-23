/*https://leetcode.com/problems/3sum/description/
 *time: 48min
 *solution
 *medium
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		vector<vector<int>> res;
		
		for (int i = 0; i < (int)nums.size(); i++) {
			int target = -1 * nums[i];
			int head = i + 1;
			int tail = nums.size() - 1;

			while (head < tail) {
				int sum = nums[head] + nums[tail];

				if (sum < target)
					head++;
				else if (sum > target)
					tail--;
				else {
					vector<int> triplet(3, 0);
					triplet[0] = nums[i];
					triplet[1] = nums[head];
					triplet[2] = nums[tail];
					res.push_back(triplet);

					while (head < tail && nums[head] == triplet[1])
						head++;

					while (head < tail && nums[tail] == triplet[2])
                                                tail--;
				}
			}	

			while (i + 1 < num.size() && num[i + 1] == num[i]) 
            			i++;
			
		}
		return res;
	}
};
