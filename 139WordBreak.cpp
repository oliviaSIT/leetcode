/*https://leetcode.com/problems/word-break/description/
 *time:43min
 *solution:dp
 *medium
 */

#include <iosream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> dict;
		for (auto words: wordDict) {
			dict.insert(words);
		}
     
		s = "!" + s;
		vector<bool> dpArray(s.size());
		dpArray[0] = true;

		for (int i = 0; i < s.size(); i++){
			for (int j = i + 1; j < s.size(); j++) {
				if (dpArray[j]) 
					continue;

				if (dict.find(s.substr(i + 1, j - i)) != dict.end() && dpArray[i])
					dpArray[j] = true;
			}
		}

		return dpArray[dpArray.size()-1];
	}
};

int main() {
	Solution sol;
	cout << sol.wordBreak("leetcode", {"leet","code"}) << endl;
	return 0;
}
