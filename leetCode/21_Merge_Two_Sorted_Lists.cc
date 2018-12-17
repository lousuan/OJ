struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        ListNode* head = new ListNode(0);
        auto* temp = head;
        while (l1 != nullptr && l2 != nullptr) {
            if ((l1->val) < (l2->val)) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }

        temp->next = l1 == nullptr ? l2 : l1;
        temp = head;
        head = head->next;
        delete temp;
        return head;
    }
};