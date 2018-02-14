/*https://leetcode.com/problems/insert-interval/description/
 *time:32min
 *solution:
 *hard
 */

#include <iostream>
#include <vector>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval(): start(0), end(0) {}
	Interval(int s, int e): start(s), end(e) {}
};

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> res;
		int len = intervals.size();
		if (len == 0) {
			res.push_back(newInterval);
			return res;
		}

		int st = newInterval.start, ed = newInterval.end;
		for (int i = 0; i < len; i++) {
			const Interval& cur = intervals[i];
			if (cur.end < newInterval.start) {
				res.push_back(cur);
			} else if (cur.start > newInterval.end) {
				if (ed < cur.start) {
					res.push_back(Interval(st, ed));
					ed = INT_MAX;
				}
				res.push_back(cur);
			} else {
				st = min(cur.start, st);
				ed = max(cur.end, ed);
			}
		}

		if (ed != INT_MAX)
			res.push_back(Interval(st, ed));

		return res;	

	}
};
