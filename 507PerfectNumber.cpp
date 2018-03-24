/*https://leetcode.com/problems/perfect-number/description/
 *time:15min
 *solution:
 *easy
 */

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1)
                return false;
           
        vector<int> factor = findFactor(num);
           
        for (int i = 0; i < (int)factor.size(); i++)
                num -= factor[i];
            
        return (num == 0);
    }
        
    vector<int> findFactor(int num) {
            vector<int> factor{1};
            for (int i = 2; i * i <= num; i++) {
                    if (num % i == 0) {
                            factor.push_back(i);
                            factor.push_back(num / i);
                    }
            }
            
            return factor;
    }    
};
