/*https://leetcode.com/problems/beautiful-arrangement/description/
 *time:40min
 *solution:backtracking , similar as permutation
 *medium
 */

class Solution {
public:
    int countArrangement(int N) {
        if (N < 1)
            return 0;
        int res = 0;
        vector<int> cur;
        vector<bool> isUsed(N, false);
        count(res, cur, isUsed, N, 1);
        return res;
    }
    
    void count(int& res, vector<int>& cur, vector<bool>& isUsed, int N, int index) {
        if (cur.size() == N) {
            res++;
            return;
        }
        
        for (int i = 1; i <= N; i++) {
            if (isUsed[i - 1] == false && (i % index == 0 || index % i == 0)) {
                isUsed[i - 1] = true;
                cur.push_back(i);
                count(res, cur, isUsed, N, index + 1);
                cur.pop_back();
                isUsed[i - 1] = false;
            }
        }
            
    }
};
