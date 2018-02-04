/*https://leetcode.com/problems/jewels-and-stones/description/
 * time:
*/

#include <iostream>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
	int numJewelsInStones(string J, string S) {
        	int res = 0;
       		set<char> setJ(J.begin(), J.end());
        	for (char s : S) {
			if (setJ.count(s)) 
				res++;
		}
        	return res;
        } 
};

int main() {
	Solution sol;
	cout << sol.numJewelsInStones("aA", "aAAbbbb") << endl;
	cout << sol.numJewelsInStones("z", "ZZ") << endl;
	return 0;
}
