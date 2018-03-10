/*https://leetcode.com/problems/isomorphic-strings/description/
 *time:18min
 *solution: hash map & set
 *corner case: ab -> aa
 *easy 
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;
        
        unordered_map<char, char> map;
        unordered_set<char> set;
        for(int i = 0; i < (int)s.length(); i++) {
            if (map.find(s[i]) == map.end()) {
                map[s[i]] = t[i];
            
                if (set.find(t[i]) != set.end())
                    return false;
                
                set.insert(t[i]);
            }
            
            else{
                if (map[s[i]] != t[i]) {
                    return false;
                } else {
                    continue;
                }
            }
        }
                                
        return true;
    }
};
