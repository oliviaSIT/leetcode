/*https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *time:58min
 *solution:use pointor n1 to record the head->need reverse
 *hard
 */

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNde *dummy = new ListNode(0);
		dummy->next = head;
		head = dummy;
		while (head->next != NULL) 
			head = reverseNode(head, k);

		return dummy->next;
	}

//reverse the next k nodes AFTER head: head->n1->n2..->nk->.. => head->nk->nk-1...->n1->..
//return n1 (the next head)
	ListNode* reverseNode(ListNode* head, int k) {
		LiseNode* node = head;
		for (int i = 0; i < k; i++) {
			if (node->next == NULL)
				return node;
			else node = node->next;
		}

		ListNode* n1 = head->next;
		ListNode* cur = n1;
		ListNode* next = cur->next;
		for (int i = 0; i < k - 1; i++) {
			if (next == NULL) {
				n1->next = NULL;
				break;
			}

			ListNode* temp = next->next;
			next->next = cur;
			cur = next;
			next = temp;
		}

		head->next = cur;
		n1->next = next;

		return n1;
	}
};
