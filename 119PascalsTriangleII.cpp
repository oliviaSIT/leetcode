/*https://leetcode.com/problems/pascals-triangle-ii/description/
 *time:24min
 *solution:recurse
 *easy
 */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1);
        
        if (rowIndex < 1)
            return res;
        
        if (rowIndex == 1) {
            res.push_back(1);
            return res;
        }
        
        if (rowIndex == 2) {
            res.push_back(2);
            res.push_back(1);
            return res;
        }
        
        vector<int> before = getRow(rowIndex - 1);
        for (int i = 1; i < rowIndex; i++) {
            res.push_back(before[i - 1] + before[i]);
        }
        
        res.push_back(1);
        
        return res;
                
    }
};
