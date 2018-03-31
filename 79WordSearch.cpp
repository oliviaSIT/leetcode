/*https://leetcode.com/problems/word-search/description/
 *time:63min
 *solution:DFS+backtracking, use '*' to mark the char which has been visited
 *medium
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		int M = board.size(), N = board[0].size(), sLen = word.size();
		
		if (M && N && sLen) {
			for (int i = 0; i < M; i++) {
				for (int j = 0; j < N; j++) {
					if (dfs(board, i, j, word, 0, M, N, sLen))
						return true;
				}
			}
		}
		
		return false;
	}

private:
	bool dfs(vector<vector<char>>& board, int row, int col, const string& word, int start, int M, int N, int sLen) {
		char curC = board[row][col];
		bool res = false;
		if (curC != word[start])
			return false;

		if (start == sLen - 1)
			return true;

		board[row][col] = '*';

		if (row > 0)
			res = dfs(board, row - 1, col, word, start + 1, M, N, sLen);

		if (!res && row < M - 1)
			res = dfs(board, row + 1, col, word, start + 1, M, N, sLen);

		if (!res && col > 0)
			res = dfs(board, row, col - 1, word, start + 1, M, N, sLen);

		if (!res && col < N - 1)
			res = dfs(board, row, col + 1, word, start + 1, M, N, sLen);

		board[row][col] = curC;

		return res;
	}
};

int main() {
	Solution sol;
	vector<vector<char>> v{{'a', 'b', 'c', 'e'}, {'s', 'f', 'c', 's'}, {'a', 'd', 'e', 'e'}};
	cout << sol.exist(v, "see") << endl;
	return 0;
}
