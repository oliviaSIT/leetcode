/*https://leetcode.com/problems/intersection-of-two-linked-lists/description/
  time:30min
  sol:First pass count length of two lists. Then move the pointer of the longer list ahead first. Then move both pointers and check if same 
*/

#include <iostream>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
	int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		*ListNode p1 = headA, p2 = headB;

		if (p1 == NULL || p2 == NULL) 
			return NULL;

		while (p1 != NULL && p2 != NULL && p1 != p2) { // conditon(p1 != p2) is necessary because two lists canbe the same.
			p1 = p1.next;
                        p2 = p2.next;

			if (p1 == p2)
				return p1;
			
			if (p1 == NULL)
				p1 = headB;

			if (p2 == NULL)
                                p2 = headA;
		}
		
		return p1;
			        
        }
};
