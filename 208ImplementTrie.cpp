/*https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *time:
 *solution:
 *medium
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Trie {
private:
    class Node {
    public:
        vector<Node*> next;
        bool isWord;
    
        Node(): isWord(false) {
            for (int i = 0; i < 26; i++)
                next.push_back(nullptr);
        }
        
    };
    
    Node root;
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* p = &root;
        for (int i = 0; i < (int)word.size(); i++) {
            if (p->next[word[i] - 'a'] == NULL)
                p->next[word[i] - 'a'] = new Node();
            p = p->next[word[i] - 'a'];
        }
        p->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* p = &root;
        for (int i = 0; i < (int)word.size(); i++) {
            if (p->next[word[i] - 'a'] == NULL)
                return false;   
            p = p->next[word[i] - 'a'];
        }
        
        return p->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* p = &root;
        for (int i = 0; i < (int)prefix.size(); i++) {
            if (p->next[prefix[i] - 'a'] == NULL)
                return false;
            
            p = p->next[prefix[i] - 'a'];
        }
        
        return true;
    }
};

int main() {
	Trie* obj = new Trie();
	obj->insert("a");
	cout << obj->search("a") << endl;
	return 0;
}
