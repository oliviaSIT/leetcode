/*https://leetcode.com/problems/merge-intervals/description/
 *time:
 *solution: sort+lamda
 *medium
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
        int start;
        int end;
        Interval() : start(0), end(0) {}
        Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
        vector<Interval> merge(vector<Interval>& intervals) {
                if (intervals.empty())
                        return vector<Interval> {};

                vector<Interval> res;
                sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});

                res.push_back(intervals[0]);
                for (size_t i = 1; i < intervals.size(); i++) {                 if (res.back().end < intervals[i].start) {
                                res.push_back(intervals[i]);
                        } else {
                                res.back().end = max(res.back().end, intervals[i].end);
                        }
                }

                return res;
        }
};

void printIntervalVec(const vector<Interval>& vec) {
	for (const Interval& interval : vec) {
		cout << "{" << interval.start << "," << interval.end << "} ";
	}
	cout << endl;
}

int main() {
	Solution sol;
	vector<Intervals> vec = {{74, 78}, {61, 63}};
	printIntervalVec(sol.merge(vec));

    return 0;
}

