/*https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *time:53min
 *solution:backtracing
 *medium
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> res;
		
		if (digits.length() == 0)
			return res;

		string cur;
		vector<vector<char>> candidate = findCandidate(digits);
		backTracking(res, cur, candidate, 0);
		return res;
	}

private:
	vector<vector<char>> findCandidate(const string& digits) {
		vector<vector<char>> candidate;
		for (int i = 0; i < (int)digits.length(); i++) {
			vector<char> temp;
			switch (digits[i]) {
				case '0':
					temp.push_back(' ');
					break;
				case '1':
					temp.push_back(' ');
					temp.push_back(' ');
					break;
				case '2':
					temp.push_back('a');
					temp.push_back('b');
					temp.push_back('c');
					break;
				case '3':
					temp.push_back('d');
                                        temp.push_back('e');
                                        temp.push_back('f');
					break;
				case '4':
					temp.push_back('g');
                                        temp.push_back('h');
                                        temp.push_back('i');
					break;
				case '5':
					temp.push_back('j');
                                        temp.push_back('k');
                                        temp.push_back('l');
					break;
				case '6':
					temp.push_back('m');
                                        temp.push_back('n');
                                        temp.push_back('o');
					break;
				case '7':
					temp.push_back('p');
                                        temp.push_back('q');
                                        temp.push_back('r');
					temp.push_back('s');
					break;
				case '8':
					temp.push_back('t');
                                        temp.push_back('u');
                                        temp.push_back('v');
					break;
				case '9':
					temp.push_back('w');
                                        temp.push_back('x');
                                        temp.push_back('y');
                                        temp.push_back('z');
					break;
			}
			
			candidate.push_back(temp);
		}
		
		return candidate;
	}

	void backTracking(vector<string>& res, string& cur, vector<vector<char>>& candidate, int l) {
		if (cur.length() == candidate.size()) {
			res.push_back(cur);
			return;
		}

		for (int i = 0; i < (int)candidate[l].size(); i++) {
			cur += candidate[l][i];
			backTracking(res, cur, candidate, l + 1);	
			cur.pop_back();
		}		
	}
};

int main() {
	Solution sol;
	vector<string> res = sol.letterCombinations("23");
	for (int i = 0; i < (int)res.size(); i++) {
		cout << res[i] << ' ';
	}
	cout << endl;
	return 0;
}
