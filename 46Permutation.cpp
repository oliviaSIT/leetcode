/*https://leetcode.com/problems/permutations/description/
 *time:55min
 *solution:dfs
 *medium
 */

#include <iostream>
#include <vector>

using namespace std;
/*
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		permute(nums, 0, res);
		return res;
	}

	void permute(vector<int>& nums, int st, vector<vector<int>>& res) {
		if (st >= nums.size()) {
			res.push_back(nums);
			return;
		}

		for (int i = st; i < nums.size(); i++) {
			swap(nums[st], nums[i]);
			permute(nums, st + 1, res);
			swap(nums[st], nums[i]);
		}
	}
};
*/

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> permutations;
        if(num.size() == 0) //invalid corner case check
            return permutations;
        vector<int> curr;
        vector<bool> isVisited(num.size(), false); //using this bool type array to check whether or not the elments has been visited
        backTracking(permutations,curr,isVisited,num);
        return permutations;
    }

    void backTracking(vector<vector<int>>& ret, vector<int> curr, vector<bool> isVisited, vector<int> num)
    {
        if(curr.size() == num.size())
        {
            ret.push_back(curr);
            return;
        }

        for(int i = 0; i < num.size(); ++i)
        {
            if(isVisited[i] == false)
            {
                isVisited[i] = true;
                curr.push_back(num[i]);
                backTracking(ret,curr,isVisited,num);
                isVisited[i] = false;
                curr.pop_back();
            }
        }
    }
};
int main() {
	Solution sol;
	vector<int> v{1, 2, 3, 4};
	vector<vector<int>> res = sol.permute(v);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++)
			cout << res[i][j] << ' ';

		cout << endl;
	}
	return 0;
}
