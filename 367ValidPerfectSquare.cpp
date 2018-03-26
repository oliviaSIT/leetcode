/*https://leetcode.com/problems/valid-perfect-square/description/
 *time: 35min
 *solution: binary
 *corner case: st + 1 < ed, st or ed is the sqrt root of num, overflow
 *easy
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0)
            return false;
        if (num <= 1)
            return true;

        long st = 2, ed = num / 2;
        while (st + 1 < ed) {
            long md = st + (ed - st) / 2;
            long square = md * md;
            cout << st << ' ' << ed << ' ' << md << ' ' << square << endl;
            if (square == num)
                return true;
            if (square < num)
                st = md;
            else
                ed = md;
        }

        if (st * st == num || ed * ed == num)
            return true;
        
        return false;
    }
};

int main() {
	Solution sol;
	cout << sol.isPerfectSquare(808201) << endl;
	return 0;
}
