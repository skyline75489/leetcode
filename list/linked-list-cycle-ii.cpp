class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *fast,*slow;
        slow = head;
        fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode *slow2 = head;
                while (slow2 != slow) {
                    slow = slow->next;
                    slow2 = slow2->next;
                }
                return slow2;
            }
        }
        return nullptr;
    }
};