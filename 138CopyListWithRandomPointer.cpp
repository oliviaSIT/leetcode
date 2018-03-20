/*https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *time:23min
 *solution:hash table
 *medium
 */

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> old2new;
        RandomListNode* dummy = new RandomListNode(-1);
        RandomListNode* tmp = head;
        RandomListNode* curr = dummy;
        while (tmp) {
            RandomListNode* newNode = new RandomListNode(tmp->label);
            old2new[tmp] = newNode;
            curr->next = newNode;
            curr = curr -> next;
            tmp = tmp->next;
        }
        tmp = head;
        while (tmp) {
            if (tmp->random) {
                old2new[tmp]->random = old2new[tmp->random];
            }
            tmp = tmp-> next;
        }
        return dummy->next;
    }        
    
};
