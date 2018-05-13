/*https://leetcode.com/problems/course-schedule-ii/description/
 *time:13min
 *Solution:Topological Sorting
 *medium
 */

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> order;
        vector<int> visit(numCourses, 0);

		for (int i = 0; i < numCourses; i++) {
			if (!visit[i])
				if (hasCycle(i, visit, prerequisites, order)) {
					order.clear();
                    return order;
                }
		}

       // reverse(order.begin(), order.end());
        if (order.size() == 0) {
            for (int i = numCourses - 1; i >= 0; i--)
                order.push_back(i);
        }
            
        
		return order;
    }
    
    bool hasCycle(int node, vector<int>& visit, vector<pair<int, int>>& prerequisites, vector<int>& order) {
		if (visit[node] == 2)
			return false;

		if (visit[node] == 1)
			return true;

		visit[node] = 1;

		for (int i = 0; i < prerequisites.size(); i++) {
			if (prerequisites[i].first == node) {
				if (hasCycle(prerequisites[i].second, visit, prerequisites, order))
					return true;
			}
		}

		visit[node] = 2;
        order.push_back(node);
		return false;
	}
};
