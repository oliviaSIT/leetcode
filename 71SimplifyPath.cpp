/*https://leetcode.com/problems/simplify-path/description/
 *time: 59min
 *solution:stack<string>
 *medium
 */

class Solution {
public:
    string simplifyPath(string path) {
        if (path == "")
            return "";
        
        string res = "", cur = "";
        stack<string> dir;
        
        for (int i = 1; i < (int)path.size(); i++) {
            if (path[i] == '/') {
                continue;
            }
            
            cur = get(path, i);
            if (cur != ".") {
                if (cur != "..") {
                    dir.push(cur);
                } else if (!dir.empty()) 
                    dir.pop();
            }
            
            i += cur.size();
        }
        
        if(dir.empty()) 
            return "/";
        
        stack<string> reverse;
        while (!dir.empty()) {
            reverse.push(dir.top());
            dir.pop();
        }
        
        while (!reverse.empty()) {
            res += "/";
            res += reverse.top();
            reverse.pop();
        }
        
        return res;
    }
    
    string get(const string& path , int index) {
        string res;
        while (index < path.size() && path[index] != '/') {
            res += path[index];
            index++;
        }
        return res;
    }
};
