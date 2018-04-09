/*https://leetcode.com/problems/beautiful-arrangement-ii/description/
 *time:63min
 *solution:1, k+1, 2, k, 3, k-1...
 *medium
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

/* the answer is right but time exceeds
class Solution {
public:
	vector<int> constructArray(int n, int k) {
		vector<int> res, cur;
		if (n < 1 || k < 1 || k > n)
			return res;

		vector<bool> isUsed(n, false);
		construct(res, cur, isUsed, n, k);
		return res;
	}

	void construct(vector<int>& res, vector<int>& cur, vector<bool>& isUsed, int n, int k) {
		if (cur.size() == n) {
			if (isK(cur, k))
				res = cur;

			return;
		}


		for (int i = 1; i <= n; i++) {
			if (isUsed[i - 1] == false) {
				isUsed[i - 1] = true;
				cur.push_back(i);
				construct(res, cur, isUsed, n, k);
				isUsed[i - 1] = false;
				cur.pop_back();
			}
		}
	}

	bool isK(vector<int>& cur, int k) {
		vector<int> temp;
		for (int i = 0; i < (int)cur.size() - 1; i++) {
			temp.push_back(abs(cur[i] - cur[i + 1]));
		}
		int count = 0;
		unordered_set<int> set;
		for (int i = 0; i < (int)temp.size(); i++) {
			if (set.find(temp[i]) == set.end()) {
				count++;
				set.insert(temp[i]);
			}
		}

		return count == k;
	}
};
*/

class Solution {
public:
        vector<int> constructArray(int n, int k) {
                vector<int> res, cur;
                if (n < 1 || k < 1)
                        return res;

		int a = 1, b = k + 1;
		while (a <= b) {
			res.push_back(a++);

			if (a <= b)
				res.push_back(b--);
		}

		for (int i = k + 2; i <= n; i++)
			res.push_back(i);
		
		return res;
	}
};

int main() {
	Solution sol;
	vector<int> res = sol.constructArray(10, 4);

	for (int i = 0; i < (int)res.size(); i++) {
		cout << res[i] << ' ';
	}

	cout << endl;
	return 0;
}
