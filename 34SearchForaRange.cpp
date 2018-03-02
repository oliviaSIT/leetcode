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
        
        int st = 0, ed = 0;
        int md = st + (ed - st) / 2;
        while (st <= ed) {
            if (nums[md] == target) {
                st = md; ed = md;
                while (nums[st] == target && st >= 0)
                    st--;
                while (nums[ed] == target && ed < nums.size())
                    ed++;
                
                res[0] = st++;
                res[1] = ed--;
                return res;
            } else if (nums[md] < target)
                st = md;
            else ed = md;
        }
        
        return res;
    }
};

int main() {
	Solution sol;
	vector<int> v{5, 7, 8, 8, 10};
	cout << sol.searchRange(v, 8)[0] << sol.searchRange(v, 8)[1] << endl;
	return 0;
}
