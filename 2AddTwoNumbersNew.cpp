/*https://leetcode.com/problems/add-two-numbers/description/

 */

#include <iostream>
#include <cmath>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int n1 = ListToInt(l1);
		int n2 = ListToInt(l2);
		int sum = n1 + n2;

		ListNode* res = intToLlist(sum);

		return res;
	}

private:
	int ListToInt(ListNode* l) {
		int digit = 0;
		int n = 0;
		do {
			n += l->val * pow(10, digit);
			digit++;
		} while (l->next != NULL);

		return n;
	}

	ListNode* intToList(int n) {
		ListNode* dummy = new ListNode(0);
		ListNode* pre = dummy;

		if (n == 0)
			return dummy;

		while (n != 0) {
			ListNode* cur = new ListNode(n % 10);
			pre->next = cur;
			pre = cur;
			n /= 10;
		}

		return dummy->next;
	}
	

};
