/*https://leetcode.com/problems/course-schedule/description/
 *time:32min
 *Solution:Topological Sorting
 *medium
 */

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> visit(numCourses, 0);
        
        for (int i = 0; i < numCourses; i++) {
            if (!visit[i])
                if (hasCycle(i, visit, prerequisites))
                    return false;
        }
        
        return true;
    }
    
    bool hasCycle(int node, vector<int>& visit, vector<pair<int, int>>& prerequisites) {
        if (visit[node] == 2)
            return false;
        
        if (visit[node] == 1)
            return true;
        
        visit[node] = 1;
        
        for (int i = 0; i < prerequisites.size(); i++) {
            if (prerequisites[i].second == node) {
                if (hasCycle(prerequisites[i].first, visit, prerequisites))
                    return true;
            }
        }
        
        visit[node] = 2;
        return false;
    }
};
