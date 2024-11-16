class Solution {
public:
    ListNode* reverse(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;

        while (k--) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Step 1: Check if there are at least `k` nodes left in the list
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (!temp) return head; // Not enough nodes to reverse
            temp = temp->next;
        }

        // Step 2: Reverse the first `k` nodes
        ListNode* newHead = reverse(head, k);

        // Step 3: Recursively reverse the remaining nodes
        head->next = reverseKGroup(temp, k);

        return newHead;
    }
};
