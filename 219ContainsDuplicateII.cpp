/*https://leetcode.com/problems/contains-duplicate-ii/description/
 *time:33min
 *solution:hash map
 *easy
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution {
public:
/*
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (nums.size() == 0 || nums.size() == 1 )
			return false;

		unordered_set<int> n;
		if (k > (int)nums.size()) 
			k = nums.size() - 1;
		
		for (int i = 0; i < (int)nums.size(); i++) {
			if (i > k) n.erase(nums[i - k - 1]);
			if (n.find(nums[i]) != n.end())
				return true;
			else n.insert(nums[i]);
		}
		return false;
	}
};
*/

	bool containsNearbyDuplicate(vector<int>& nums, int k) {
                if (nums.size() == 0 || nums.size() == 1)
                        return false;

		unordered_map<int, int> n;
                
                for (int i = 0; i < (int)nums.size(); i++) {
                        if (n.find(nums[i]) != n.end()) {
                                if (i - n[nums[i]] <= k)
                                        return true;
                                else {
					n.erase(nums[i]);
					n.insert(pair<int, int> (nums[i], i));
				}
                        } else n.insert(pair<int, int> (nums[i], i));
                }
                return false;

	}
};

int main() {
	Solution Sol;
	vector<int> v{1, 2, 1};
	cout << Sol.containsNearbyDuplicate(v, 1) << endl;
	return 0;
}
