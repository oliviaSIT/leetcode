/*https://leetcode.com/problems/reverse-words-in-a-string/description/
 *time:40min
 *solution: reverse the word, then reverse all
 *medium
 */

/* solution one: place o(n)
class Solution {
public:
    void reverseWords(string &s) {
        int len = s.size();
        if (len == 0)
            return;
        
        stack<string> st;
        string cur = "";
        istringstream iss(s);
        while (iss) {
            iss >> cur;
            st.push(cur);
            cur = "";
        }
        
        s = "";
        st.pop();
        while (!st.empty()) {
            s = s + st.top() + " ";
            st.pop();
        }
        
        s.pop_back();
        
        return;
    }
};
*/

class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty()) return;
        string ret, word;
        
        for(int i=s.size()-1; i>=0; i--) {
            if(isspace(s[i])) {
                if(i<s.size()-1 && !isspace(s[i+1])) {
                    reverse(word.begin(),word.end());
                    ret.append(word+" ");
                    word.clear();
                }
            }
            else {
                word.push_back(s[i]);
            }
        }
        
        if(!isspace(s[0])) {
            reverse(word.begin(),word.end());
            ret.append(word);
        }
        else if(!ret.empty()) {
            ret.pop_back();
        }
            
        s = ret;
    }
};

