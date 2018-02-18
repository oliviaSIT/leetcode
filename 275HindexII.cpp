/*http://leetcode.com/problems/h-index-ii/description/
 *time:61:01min
 *solution:
 *medium
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		int size = citations.size();
		if (size == 0)
			return 0;

		int st = 0, ed = size - 1;
		while (st + 1 < ed) {
			int md = st + (ed - st) / 2;
			if (citations[md] == getIndex(md, size))
				return citations[md];

			if (citations[md] > getIndex(md, size)) {
				ed = md;
			} else {
				st = md;
			}
		}

		int first = min(citations[st], getIndex(st, size));
		int second = min(citations[ed], getIndex(ed, size));

		return max(first, second);

	}

	int getIndex(int idx, int size) {
		return size - idx;
	}
};


