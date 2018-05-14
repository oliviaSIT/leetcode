/*https://leetcode.com/problems/course-schedule-iii/description/
 *time:63min
 *solution:greedy, queue
 *hard
 */

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
public:
	int scheduleCourse(vector<vector<int>>& courses) {
		sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) {return a[1] < b[1];});

		int now = 0;
		priority_queue<int> used;
		for (int i = 0; i< courses.size(); i++) {
			used.push(courses[i][0]);
			now += courses[i][0];
			if (now > courses[i][1]) {
				now -= used.top();
				used.pop();
			}
		}
		return used.size();
	}
};
