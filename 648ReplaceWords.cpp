/*
 *time:
 *solution: hash trie
 *medium:
 */

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

class Solution {
public:
	class TrieNode{
	public:
		bool end;
		string str;
		TrieNode* children[26];
		TrieNode(bool flag, string s): end(flag), str(s) {
        		memset(children, 0, sizeof(children));
        	}
    	};

	class TrieTree{
	public:
        	TrieNode* root;
		TrieTree() {
	    		root = new TrieNode(false,"");
	 	}
    
		void buildTree(vector<string>& dict){
			for(int i = 0; i < (int)dict.size(); i++)  {
				TrieNode* cur = root;
				for(int j = 0; j < (int)dict[i].size(); j++){
					if(cur->children[dict[i][j] - 'a'] == NULL) {
						cur->children[dict[i][j] - 'a'] = new TrieNode(false,"");
						cur = cur->children[dict[i][j] - 'a'];
					} else if(cur->children[dict[i][j] - 'a']->end == true){   //if a shorter root exists, we just stop build
						cur = NULL;
						break;
					} else cur = cur->children[dict[i][j] - 'a'];
				}

				if(cur != NULL) {    //mark the string and flag
					cur->end = true;
					cur->str = s;
				}
			}

			return;
		}

		string replace(string s) {
			TrieNode* cur =root;
			string res="";
			for(char c:s) {
				cur = cur->children[c-'a'];
				if(cur == NULL) 
					break;
                
				if(cur->end == true){
					res = cur->str;
					break;
				}
			}
            
			if(res != "") 
				return res;
            
			return s;
		}
	};

	string replaceWords(vector<string>& dict, string sentence) {
		stringstream sen(sentence);
		string res="";
		string token;
		TrieTree tree;
		tree.buildTree(dict);
		while(getline(sen,token,' ')) {
			res += tree.replace(token);
			res += " ";
		}

		return res.substr(0,res.size()-1);  //ignore last space
	}
};

int main() {
	Solution sol;
	vector<string> v{"cat", "bat", "rat"};
	string s = "the cattle was rattled by the battery";
	cout << sol.replaceWords(v, s) << endl;
	return 0;
}
