#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
	bool isAnagram( string s, string t ) {
		map<char, int> charFreq;

		for (char& c: s) {
			charFreq[c]++;
		}        

		for (char& c: t) {
                        charFreq[c]--;
                }

		for (auto it = charFreq.begin(); it != charFreq.end(); ++it) {
			if (it -> second != 0)
				return false;
		}

		return true;
	}
};

int main() {
	string s1 = "hello";
	string s2 = "hoell";
	Solution ans;
	cout << ans.isAnagram(s1, s2) << endl;
	return 0;
}
