/*https://leetcode.com/problems/restore-ip-addresses/description/
 *time:
 *solution:
 *medium
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> res;
		if (s.size() < 4 || s.size() > 12)
			return res;
		
		vector<string> cur;
		restore(res, cur, s, 0, 4);

		return res;
	}

	void restore(vector<string>& res, vector<string>& cur, const string& s, int st, int n) {
		if (n == 0 ) {
			if (st == (int)s.size())
				return;
			else {
				string ip = "";
				for (int i = 0; i < 3; i++) 
					ip += cur[i] + '.';
			
				ip += cur[3];
				res.push_back(ip);
				return;
			}
		}

		for (int l = 1; l <= (int)s.size() - st; l++) {
			string str = s.substr(st, l);
			int num = stoi(str);

			if (num == 0 && l > 1)
				continue;

			if (num > 0 && str[0] == '0')
				continue;

			if (num < 256) {	
				cur.push_back(str);
				restore(res, cur, s, st + l, n - 1);
				cur.pop_back();
			}
		}
	}
};
