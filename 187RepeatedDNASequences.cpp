/*https://leetcode.com/problems/repeated-dna-sequences/description/
 *time:12min
 *solution:2 hash sets
 *medium
 */

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {           
            if (s.length() < 11)
                    return {};
            
            unordered_set<string> set, resSet;
            for (int i = 0; i <= s.length() - 10; i++) {
                    string substr(s, i, 10);
                    if (set.find(substr) != set.end())
                            resSet.insert(substr);
                    else set.insert(substr);
            }
            
            return vector<string>(resSet.begin(), resSet.end());
    }
};
