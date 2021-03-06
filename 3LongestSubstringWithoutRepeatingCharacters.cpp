/*https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *time:
 *solution:
 *medium
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int maxLen = 0, curLen = 0, st = 0;
		unordered_map<char, int> hash;		

		for (int i = 0; i < (int)s.size(); i++) {
			if (hash.count(s[i])) {
				for (int j = st; j < hash[s[i]]; j++)
					hash.erase(s[j]);

				st = hash[s[i]] + 1;
				curLen = i - hash[s[i]];
			} else {
				curLen++;	
			}

			hash[s[i]] = i;
			maxLen = max(maxLen, curLen);
		}

		return maxLen;
	}
};
/*
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.length() < 2)
			return s.length();

		int res = 0;
		int st = 0, ed = 1;
		unordered_map<char, int> map{{s[st], st}};
		while (ed < s.length()) {
			auto ret = map.insert({s[ed], ed});
			
			if (!ret.second) {
				res = max(res, ed - st);
				st = map[s[ed]] + 1;
				if (map.begin() != map.find(s[ed])) 
					map.erase(map.begin(), map.find(s[ed]));

				map.erase(s[ed]);
				map.insert({s[ed],ed});
			}

			ed++;
		}

		res = max(res, ed - st);
		return res;
	}
};
*/
int main() {
	Solution sol;
	string s1 = "abcabcbb", s2 = "bbbbb", s3 = "pwwkew";
	cout << sol.lengthOfLongestSubstring(s1) << endl;
	cout << sol.lengthOfLongestSubstring(s2) << endl;
	cout << sol.lengthOfLongestSubstring(s3) << endl;
	return 0;
}
