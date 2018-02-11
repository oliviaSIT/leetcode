/*https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
 *time:33:19min
 *solution:recurse+hash
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
        vector<int> findMode(TreeNode* root) {
                unordered_map<int, int> map;
                vector<int> res;
                int modeCount = getModeCount(root, map);
        
                for(pair<int,int> p : map) {
                	if(p.second == modeCount) {
                		res.push_back(p.first);
                        }
        	}
        
        	return result;
        
        }

	int getModeCount(TreeNode* root, unordered_map<int, int> &map) {
        	if(root == NULL)
            		return 0;
        
        	if(map.find(root->val) == map.end()) {
            		map.insert(pair<int, int>(root->val, 1));
        	} else {
            		map[root->val]++;
        	}
        
        	return max(map[root->val], max(getModeCount(root->left, map), getModeCount(root->right, map)));
        }    
};

