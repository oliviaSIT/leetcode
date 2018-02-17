/*https://leetcode.com/problems/merge-k-sorted-lists/description/
 *time:40min
 *solution:Use a min heap, which take O(logn) to update but O(1) to pop.
 *hard
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
private:
	struct cmp {
		bool operator()(const ListNode* larger, const ListNode* smaller) {
			return larger->val > smaller->val;
		}
	};

public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode dummy(0);

		priority_queue<ListNode*, vector<ListNode*>, cmp> minHeap;
		for (ListNode* node : lists) {
			if (node != NULL) {
				minHeap.push(node);
			}	
		}

		ListNode* cur = &dummy;
		while (!minHeap.empty()) {
			cur->next = minHeap.top();
			cur = cur->next;
			
			ListNode* next = minHeap.top()->next;
			minHeap.pop();
			if (next != NULL) {
				minHeap.push(next);
			}
		}

		return dummy.next;
	}

};
