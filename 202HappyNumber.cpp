/*https://leetcode.com/problems/happy-number/description/
 *time:18min
 *solution: use set to record the number which has occured
 *easy
 */
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		unordered_set<int> occurred;

		while (n != 1) {
			n = happy(n);
			if (occurred.find(n) != occurred.end())
				return false;

			occurred.insert(n);
		}

		return true;	
	}

	int happy(int n) {
                int res = 0;

                while (n != 0) {
                        int t = n % 10;
                        res += t * t;
                        n /= 10;
                }

                return res;
        }
};

int main() {
	Solution sol;
	cout << sol.isHappy(19) << endl;
	cout << sol.isHappy(20) << endl;
	return 0;
}
