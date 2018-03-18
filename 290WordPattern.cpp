/*https://leetcode.com/problems/word-pattern/description/
 *time:29min
 *solution: 2 hash maps, istringstream
 *easy
 */

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, int> p2i;
        map<string, int> w2i;
        istringstream in(str);
        int i = 0, n = pattern.size();
        string word;
        while (in >> word) {
            if (i == n || p2i[pattern[i]] != w2i[word])
                return false;
            
            p2i[pattern[i]] = i + 1;
            w2i[word] = i + 1;
            i++;
        }
        return i == n;
    }
};
