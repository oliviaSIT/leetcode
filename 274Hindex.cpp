/*https://leetcode.com/problems/h-index/description/
 *time:31:03
 *solution: greater, Use a counter start from 0 to count how many papers are larger than the counter. When the counter is same or larger than the index, previously there are h paper larger or equal than h (as counter hasn't increase when hit paper h - 1). From the defination: the max i of (min(n[i], i + 1), where i start from 0.
 *medium
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		if (citations.empty())
			return 0;

		sort(citations.begin(), citations.end(), std::greater<int>());

		int res = 0;
		for (int i = 0; i < (int)citations.size(); i++) {
			if (citations[i] > res)//notice cannot be >=, or res will be 1 larger than correct result
				res++;
		}

		return res;
	}
};

int main() {
	Solution sol;

	vector<int> cications = {3, 0, 6, 1, 5};
	cout << sol.hIndex(cications) << endl;

	return 0;
}
