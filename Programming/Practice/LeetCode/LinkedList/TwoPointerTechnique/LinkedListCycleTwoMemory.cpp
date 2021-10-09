#include <iostream>
#include <unordered_map>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x): val(x), next(NULL) { }
};
class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		if(head == NULL) return nullptr;
		std::unordered_map<ListNode*, bool> visited;
		while(head->next != NULL) {
			auto& entry = visited[head];
			if(entry) {
				return head;
			}
			entry = true;
			head = head->next;
		}
		return nullptr;
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
        std::cout << solution.detectCycle(node_11)->val << std::endl;
        std::cout << solution.detectCycle(node_21)->val << std::endl;
        std::cout << solution.detectCycle(node_31) << std::endl;
}
