/*https://leetcode.com/problems/game-of-life/description/
 *time:
 *solution:dp
 *medium
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		if (board.size() == 0 || board[0].size() == 0)
            		return;
			
		vector<int> neibor_x(board[0].size(), 0);
		vector<vector<int>> neibor(board.size(), neibor_x);

		for (int i = 0; i < (int)board.size(); i++) {
			for (int j= 0; j < (int)board[0].size(); j++) {
				neibor[i][j] = neiborCount(board, i, j);
			}
		}

		for (int i = 0; i < (int)board.size(); i++) {
                        for (int j= 0; j < (int)board[0].size(); j++) {
                                if ((neibor[i][j] == 2 && board[i][j] == 1) || neibor[i][j] == 3) 
					board[i][j] = 1;
				else board[i][j] = 0;
                        }
                }

	}

private:
	int neiborCount(const vector<vector<int>>& board, int i, int j) {
		int count = 0;
		for (int h = i - 1; h <= i + 1; h++) {
			if (h < 0 || h >= (int)board.size())
                		continue;

			for (int w = j - 1; w <= j + 1; ++w) {
				if (w < 0 || w >= (int)board[0].size())
					continue;

				if (h == i && w == j)
					continue;

				if (board[h][w] == 1)
					count++;
			}
		}	
		return count;
	}
};


int main() {
	Solution sol;
	vector<vector<int>> board = {
					{1, 1, 0, 0},
					{0, 1, 0, 0},
					{0, 0, 0, 0}
							};

	sol.gameOfLife(board);
	for (vector<int>& vec : board) {
		for (int& n : vec) {
			cout << n << " ";
		}
		cout << endl;
 	}

	return 0;
}
