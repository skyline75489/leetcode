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
    int getListLength(ListNode *head) {
        if (head == nullptr) {
            return 0;
        }
        int length = 0;
        ListNode *p = head;
        while (p!=nullptr) {
            p = p->next;
            length ++;
        }
        return length;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = getListLength(headA);
        int lengthB = getListLength(headB);
    
        if (lengthA > lengthB) {
            std::swap(headA, headB);
        };
        int distance = abs(lengthB - lengthA);
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        while(distance--) {
            p2 = p2->next;
        }
        while (p1 != nullptr && p2 != nullptr) {
            if (p1 == p2)
                return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        return NULL;
    }
};