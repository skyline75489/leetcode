class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // 空指针直接返回，第一次提交被坑在这里了
        if (!head) {
            return head;
        }
        ListNode *p = head;
        while (p->next) {
            if (p->next->val == p->val) {
                ListNode *d = p->next;
                p->next = p->next->next;
                delete d;
            } else {
                p = p->next;
            }
        }
        return head;
    }
};