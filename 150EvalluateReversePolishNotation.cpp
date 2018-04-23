/*https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 *time:23min
 *solution:stack, pay attention that y comes first, then x
 *medium
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		stack<int> s;

		for (int i = 0; i < (int)tokens.size(); i++) {
			if (isOp(tokens[i])) {
				int y = s.top();
				s.pop();
				int x = s.top();
				s.pop();
				s.push(evaluate(x, y, tokens[i]));
			} else {
				s.push(stoi(tokens[i], nullptr, 10));
			}
		}
		return s.top();
	}

	bool isOp(string s) {
		if (s == "+" || s == "-" || s == "*" || s == "/")
			return true;

		return false;
	}

	int evaluate(int x, int y, string op) {
		if (op == "+")
			return x + y;
		else if (op == "-")
			return x - y;
		else if (op == "*")
			return x * y;
		else if (op == "/")
			return x / y;
	}
};

int main() {
	Solution sol;
	vector<string> v{"2", "3", "+"};
	cout << sol.evalRPN(v) << endl;
	return 0;
}

