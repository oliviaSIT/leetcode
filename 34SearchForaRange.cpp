/*https://leetcode.com/problems/search-for-a-range/description/
 *time:
 *solution:
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res{-1, -1};

		if (nums.size() == 0 || nums[0] > target || nums[nums.size() - 1] < target)
			return res;

		int st = 0, ed = nums.size() - 1;
		int md = findTarget(nums, st, ed, target);
		res[0] = md;
		res[1] = md;
		if (md == -1)
			return res;

		st = findTarget(nums, 0, md - 1, target);
		ed = findTarget(nums, md + 1, nums.size() - 1, target);
		if (st != -1) {
			res[0] = st;
			st = findTarget(nums, 0, st - 1, target);
		}

		if (ed != -1) {
			res[1] = ed;
			ed = findTarget(nums, ed + 1, nums.size() - 1, target);
		}

		return res;
	}

private:
	int findTarget(vector<int>& nums, int st, int ed, int target) {
		if (st > ed)
			return -1;
	
		int md = st + (ed - st) / 2;
		if (nums[md] == target)
			return md;
		else if (nums[md] < target) {
				return findTarget(nums, md + 1, ed, target);
			}
			else return findTarget(nums, st, md - 1, target);
	}
};
/*
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1, -1};
        
        if (nums.size() == 0 || nums[0] > target || nums[nums.size() - 1] < target)
            return res;
        
        int st = 0, ed = nums.size() - 1;
        int md = st + (ed - st) / 2;
        while (st <= ed) {
            if (nums[md] == target) {
                st = md; ed = md;
                while (nums[st] == target && st >= 0)
                    st--;
                while (nums[ed] == target && ed < nums.size())
                    ed++;
                
                res[0] = ++st;
                res[1] = --ed;
                return res;
            } else if (nums[md] < target)
                st = md;
            else ed = md;
        }
        
        return res;
    }
};
*/

int main() {
	Solution sol;
	vector<int> v{5, 7, 8, 8, 10};
	cout << sol.searchRange(v, 8)[0] << sol.searchRange(v, 8)[1] << endl;
	return 0;
}
