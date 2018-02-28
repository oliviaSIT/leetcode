/*https://leetcode.com/problems/degree-of-an-array/discuss/108651/straightforward-c++-solution-35ms
 *time:42min
 *solution:Using two hash map.One records the starting index for the character.The other records the frequency of the character.
 *easy
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
	int findShortestSubArray(vector<int>& nums) {
		if (nums.size() == 0 || nums.size() == 1)
			return nums.size();

		int fre = 0;
		int len = nums.size();//When more than two character have the same frequency, just compare their length, choose the shorter one;Once a certain character’s frequency is bigger than others. we update the variable len
		unordered_map<int, int> startIndex, count;
		for (int i = 0; i < (int)nums.size(); i++) {
			if (startIndex.count(nums[i]) == 0) 
				startIndex[nums[i]] = i;

			count[nums[i]]++;

			if (count[nums[i]] == fre)
				len = min(len, i - startIndex[nums[i]] + 1);

			if (count[nums[i]] > fre) {
				len = i - startIndex[nums[i]] + 1;
				fre = count[nums[i]];
			}
		}

		return len;
	}
};

int main() {
	Solution sol;
	vector<int> v{1, 2, 2, 3, 1};
	cout << sol.findShortestSubArray(v) << endl;
	return 0;
}
