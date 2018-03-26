/*https://leetcode.com/problems/excel-sheet-column-number/description/
 *time:6min
 *solution:
 *easy
 */
class Solution {
public:
    int titleToNumber(string s) {
        int l = s.length(), res = 0;
        for (int i = 0; i < l; i++) {
                res += (pow(26, l - i - 1) * (s[i] - 'A' + 1));
        }
            
        return res;
    }
};
