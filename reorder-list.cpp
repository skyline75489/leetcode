/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == nullptr) {
            return;
        }

        ListNode *p = head;
        vector<ListNode *> v;
        while (p) {
            v.push_back(p);
            p = p->next;
        }
        unsigned long len = v.size();
        bool even = len % 2 == 0;
        for (auto first = v.begin(), last = prev(v.end()); even ? first != prev(last) : first != last; first++, last-- ) {
            ListNode *curr = *first;
            ListNode *tmp = curr->next;
            ListNode *mid = *last;
            curr->next = mid;
            mid->next = tmp;
        }
        ListNode *newTail = v[len/2];
        newTail->next = nullptr;
    }
};