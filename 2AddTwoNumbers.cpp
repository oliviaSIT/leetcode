/*https://leetcode.com/problems/add-two-numbers/description/
 *time:
 *solution:
 *medium
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode*, l2) {
		vector<int> v1 = listToVector(l1);//l1 = 1->2->3 v1=123
		vector<int> v2 = listToVector(l2);
		vector<int> sum;

		int len = max(v1.size(), v2.size());
		if (v1.size() < v2.size()) {
			addZero(v1, len - (int)v1.size());
		} else {
			addZero(v2, len - (int)v2.size());
		}

		int s = 0;
		for (int i = 0; i < len; i++) {
			if (v1[i] + v2[i] + s < 10) {
				sum.push_back(v1[i] + v2[i] + s);
				s = 0;
			} else {
				sum.push_back(0);
				s = 1;
			}
		}

		if (s == 1)
			sum.push_back(1);

		// make a list
		ListNode* head = new ListNode(0);
		ListNode* pre = head;
		for (int i = 0; i < (int)sum.size(); i++) {
			ListNode* cur = new ListNode(sum[i]);
			pre->next = cur;
			pre = cur;
		}

		return head->next;
	}

private:
	vector<int> listToVector(ListNode* l) {
		vector<int> v;
		do {
			v.push_back(l->val);
		} while (l->next != NULL);

		return v;

	}

	void addZero(vector<int>& v, int n) {
		for (int i = 0; i < n; i++)
			v.push_back(0);
	}
};
