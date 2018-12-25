//  0 -> 1 -> 2 -> 3 -> 4 -> 5
//  |    |    |    |
// pre  cur  nex  tmp

//  0 -> 2 -> 1 -> 3 -> 4 -> 5
//  |         |    |    |
// pre       cur  nex  tmp

//  0 -> 3 -> 2 -> 1 -> 4 -> 5
//  |              |    |    |
// pre            cur  nex  tmp

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* const head, int k) {
        if (head == nullptr || k == 1) return head;

        ListNode* preheader = new ListNode(0);
        preheader->next = head;
        int num = 0;

        ListNode *pre = preheader, *cur = preheader, *next;

        while (cur = cur->next) {
            // cur = cur->next;
            ++num;
        }

        while (num >= k) {
            cur = pre->next;
            next = cur->next;
            for (int i = 1; i != k; ++i) {
                cur->next = next->next;
                next->next = pre->next;
                pre->next = next;
                next = cur->next;
            }
            pre = cur;
            num -= k;
        }

        delete preheader;
        return head;
    }
};