#include <queue>
#include <vector>

using std::priority_queue;
using std::vector;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);
        for (auto list : lists) {
            if (list != nullptr) {
                queue.push(list);
            }
        }
        if (queue.empty()) {
            return nullptr;
        }
        ListNode* temp = head;
        while (!queue.empty()) {
            temp->next = queue.top();
            queue.pop();
            temp = temp->next;
            if (temp->next != nullptr) {
                queue.push(temp->next);
            }
        }
        temp = head;
        head = head->next;
        delete temp;
        return head;
    }

private:
    priority_queue<ListNode*, vector<ListNode*>, compare> queue;
};