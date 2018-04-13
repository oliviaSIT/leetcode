/*https://leetcode.com/problems/n-queens/description/
 *time:
 *solution:backtracking
 *hard
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
	vector<bool> computeValidSlots(const vector<int>& prevRows, const int curRow, const int n) {
		vector<bool> availableSlots(n, true);
		for (int preRow = 0; preRow < (int)prevRows.size(); ++preRow) {
			int pos = prevRows[preRow];
			availableSlots[pos] = false;
			int diff = curRow - preRow;
			if (pos - diff >= 0)
				availableSlots[pos - diff] = false;
			if (pos + diff < n)
				availableSlots[pos + diff] = false;
		}
		return availableSlots;
	}

	vector<string> generateRes(const vector<int>& rows, const int n) {
		vector<string> res;
		for (const int& i : rows) {
			string row(n, '.');
			row[i] = 'Q';
			res.push_back(row);
		}
		return res;
	}

	void nQueensHelper(int row, const int n, vector<int>& prevRows, vector<vector<string>>& reses) {
		if (row == n) {
			reses.push_back(generateRes(prevRows, n));
			return;
		}

		vector<bool> availableSlots = computeValidSlots(prevRows, row, n);
		for (int i = 0; i < n; ++i) {
			if (!availableSlots[i])
				continue;
			prevRows.push_back(i);
			nQueensHelper(row + 1, n, prevRows, reses);
			prevRows.pop_back();
		}
	}

public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> reses;
		if (n <= 0)
			return reses;
		vector<int> prevRows;
		nQueensHelper(0, n, prevRows, reses);
		return reses;
	}
};

int main() {
	Solution sol;

	vector<vector<string>> res = sol.solveNQueens(4);
	for (const vector<string>& v : res) {
		for (const string& s : v)
			cout << s << endl;
		cout << endl;
	}

	return 0;
}
