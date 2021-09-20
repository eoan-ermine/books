#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) { }
};

class Solution {
public:
	bool hasCycle(ListNode* head) {
		for(ListNode* ptr = head; head != NULL && head->next != NULL;) {
			head = head->next->next;
			ptr = ptr->next;
			if(ptr == head) return true;
		}
		return false;
	}
};

int main() {
	// Example 1

	ListNode* node_11 = new ListNode(3);
	ListNode* node_12 = new ListNode(2);
	ListNode* node_13 = new ListNode(0);
	ListNode* node_14 = new ListNode(-4);

	node_11->next = node_12;
	node_12->next = node_13;
	node_13->next = node_14;
	node_14->next = node_12;

	// Example 2

	ListNode* node_21 = new ListNode(1);
	ListNode* node_22 = new ListNode(2);

	node_21->next = node_22;
	node_22->next = node_21;

	// Example 3

	ListNode* node_31 = new ListNode(1);

	Solution solution;
	std::cout << solution.hasCycle(node_11) << std::endl;
	std::cout << solution.hasCycle(node_21) << std::endl;
	std::cout << solution.hasCycle(node_31) << std::endl;
}
