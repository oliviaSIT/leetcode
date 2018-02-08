/*https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *time: 35:34min
 *Solution: frequency + slip window
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
        vector<int> findAnagrams(string s, string p) {
		vector<int> res;

		
		if (s.length() < p.length()) 
			return res;

        	vector<int> sf(26, 0);// the frequency of characters in string s
		vector<int> pf(26, 0);// the frequency of characters in string p
			
		// counter the frequency
		for (size_t i = 0; i < p.length(); i++) {
			++pf[p[i] - 'a'];
			++sf[s[i] - 'a'];
		}

		if (pf == sf) 
			res.push_back(0);

		// slip the window
		for (size_t i = p.length(); i < s.length(); i++) {
			++sf[s[i] - 'a'];
			--sf[s[i - p.length()] - 'a'];//since we added one element to the right,one element to the left should be forgotten. 
			
			if (pf == sf)
				res.push_back(i - p.length() + 1);
		}

		return res;
        }
};

int main() {
	Solution sol;
	string s = "cbaebabacd", p = "abc";
	
	vector<int> ans(sol.findAnagrams(s, p));
	for (size_t i = 0; i < ans.size(); i++) 
		cout << ans[i] << ' ';

	cout << endl;
	return 0;
}
