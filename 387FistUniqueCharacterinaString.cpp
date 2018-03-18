/*https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *time:15min
 *solution: hash
 *easy
 */

class Solution {
public:
    int firstUniqChar(string s) {
        if (s.length() == 0)
            return -1;
        
        if (s.length() == 1)
            return 0;
        
        unordered_map<char, int> map;
        vector<int> index(s.length(), -1);
        
        for (int i = 0; i < (int)s.length(); i++) {
            if (map.find(s[i]) == map.end()) {
                map.insert({s[i], i});
                index[i] = i;
            } else {
                index[i] = -1;
                index[map[s[i]]] = -1;
            }
        }
                      
        for(int i = 0; i < (int)index.size(); i++) {
            if (index[i] != -1)
                return i;
        }
            
        return -1;
    }
};
