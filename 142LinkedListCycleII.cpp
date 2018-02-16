/*https://leetcode.com/problems/linked-list-cycle-ii/description/
 *time:20:11min
 *solution:Slow and fast pointers. When slow and fast meet, move one back to the begining, and both of them move 1 at a time
 *medium
 */

#include <iostream>

using namespace std;
 
struct ListNode {
	int val;
	ListNode* next;
	listNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {        
                ListNode* slow = head;
                ListNode* fast = head;

                do {
                        if (fast == NULL || fast->next == NULL) {
                                return NULL;
                        }

                        fast = fast->next->next;
                        slow = slow->next;
                } while (slow != fast);
		
		ListNode* start = head;
		while (start != slow) {
			start = start->next;
			slow = slow->next;
		}

		return start;
	}
};
