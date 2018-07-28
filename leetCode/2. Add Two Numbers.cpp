class Solution_1{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int temp = 0;
        ListNode head(0), *p = &head;
        while (l1 || l2 || temp) {
            if (l1) {
                temp += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                temp += l2->val;
                l2 = l2->next;
            }
            p->next = new ListNode(temp % 10);
            temp /= 10;
            p = p->next;
        }
        return head.next;
    }
};

class Solution_1_1{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int temp = 0;
        ListNode head(0), *p = &head;
        while (l1 || l2 || temp) {
            int d1 = l1 ? l1->val : 0;
            int d2 = l2 ? l2->val : 0;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            temp += d1 + d2;
            p->next = new ListNode(temp % 10);
            temp /= 10;
            p = p->next;
        }
        return head.next;
    }
};