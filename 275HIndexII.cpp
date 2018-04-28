/*https://leetcode.com/problems/h-index-ii/description/
 *time:28min
 *solution:binary seatch
 *medium
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		sort(citations.begin(), citations.end());

		int len = citations.size(), left = 0, right = len - 1;
		while (left <= right) {
			int mid = 0.5 * (left + right);
			if (citations[mid] == len - mid) return len - mid;
			else if (citations[mid] > len - mid) right = mid - 1;
			else left = mid + 1;
		}
		return len - left;
	}
};

int main() {
	Solution sol;
	vector<int> v{ 3, 0, 6, 1, 5 };
	cout << sol.hIndex(v) << endl;
	return 0;
}
