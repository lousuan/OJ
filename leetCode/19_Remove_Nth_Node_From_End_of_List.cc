struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto* pre = head;
        for (int i = 0; i != n; ++i) {
            pre = pre->next;
        }
        auto* post = head;
        if (pre == nullptr) {
            head = head->next;
            delete post;
            return head;
        }

        while (pre->next != nullptr) {
            post = post->next;
            pre = pre->next;
        }
        auto* temp = post->next;
        post->next = post->next->next;
        delete temp;
        return head;
    }
};

class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto* pre = head;
        int count = 0;
        while (pre != nullptr) {
            pre = pre->next;
            ++count;
        }

        pre = head;
        auto index = count - n;
        for (int i = 1; i < index; ++i) {
            pre = pre->next;
        }

        if (head == pre) {
            head = head->next;
            delete pre;
        } else {
            auto* temp = pre->next;
            pre->next = pre->next->next;
            delete temp;
        }

        return head;
    }
};
