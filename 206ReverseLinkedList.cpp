/*https://leetcode.com/problems/reverse-linked-list/description
 *time:
 *solution:set pre and cur
 */

#include <iostream>

using namespace std;

struct ListNode {
	int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
        	ListNode* NewHead = new ListNode(0);
		NewHead->next = head;
		ListNode* pre = NewHead;
		ListNode* cur = head;
		
		while (cur && cur->next) {
			ListNode* temp = pre->next;
			pre->next = cur->next;
			cur->next = cur->next->next;
			pre->next->next = temp;
		}

		return NewHead->next;
	}
};

int main() {
	Solution sol;

	ListNode n0(0), n1(1), n2(2);
	n0.next = &n1;
	n1.next = &n2;

	ListNode* t = sol.reverseList(&n0);
	while (t != NULL) {
		cout << t->val << "->";
		t = t->next;
	}
    
	cout << endl;

	return 0;
}
