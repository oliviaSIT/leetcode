/*https://leetcode.com/problems/unique-binary-search-trees/description/
 *time:
 *solution: 
Consider f_i:

choose 1 as the root, we have 0 node for the left tree, i-1 for the
right;
choose 2 as the root, we have 1 node for the left tree, i-2 for the
right;
…
choose i as the root, we have i-1 nodes for the left tree, 0 for the
right.
 *medium
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* wrong
class Solution {
public:
	int numTrees(int n) {
		if (n < 3)
			return n;

		int res = 0;
		vector<int> used{n + 1, 0};
		used[0] = 1;

		for (int i = 1; i <= n; i++) {
			cout << i << ' ';
			createTree(i, n, res, used);
		}

		return res;			
	}

	void createTree(int i, int n, int& res, vector<int>& used) {
		if (find(used.begin(), used.end(), used[0] - 1) == used.end()) {
			res++;
			used[0]++;
			cout << endl;
			return;
		}

		used[i] = used[0];
		
		for (int left = i - 1; left > 0; left--) {
			if (used[left] == used[0] - 1) {
				createTree(left, n, res, used);
				cout << left << ' ';
			}
		}

		for (int right = i + 1; right <= n; right++) {
			if (used[right] == used[0] - 1) {
				createTree(right, n, res, used);
				cout << right << ' ';
			}
		}
	}

};
*/

class Solution {
public:
        int numTrees(int n) {
                if (n < 3)
                        return n;

		vector<int> res;
		res.push_back(1);

		for (int i = 1; i <= n; i++) {
			int t = 0;
			for (int j = 0; j < i; j++) {
				t += res[j] * res[i - j - 1];
			}

			res.push_back(t);
		}

		return res.back();
	}
};

int main() {
	Solution sol;
	cout << sol.numTrees(3) << endl;
	return 0;
}
