//  0  ->  1  ->  2  ->  3  ->  4  ->  5
//  |      |      |      |
// temp  first  second

//  0  ->  2  ->  1  ->  3  ->  4  ->  5
//  |      |      |      |
// temp  second first

//  0  ->  2  ->  1  ->  3  ->  4  ->  5
//                |      |      |      |
//               temp  second first

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        auto* temp = new ListNode(0);
        temp->next = head;
        head = temp;

        while (temp != nullptr && temp->next != nullptr) {
            temp->next = swapNodes(temp->next);
            temp = temp->next->next;
        }

        temp = head->next;
        delete head;
        return temp;
    }

private:
    ListNode* swapNodes(ListNode* first) {
        auto* second = first->next;
        if (second == nullptr) {
            return first;
        }

        first->next = second->next;
        second->next = first;
        return second;
    }
};