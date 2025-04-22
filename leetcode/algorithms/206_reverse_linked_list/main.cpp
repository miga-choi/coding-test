#include <cstddef>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class ReverseLinkedList {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = nullptr;
        ListNode* result = nullptr;

        while (head) {
            temp = head->next;
            head->next = result;
            result = head;
            head = temp;
        }

        return result;
    }


    // Solution
    ListNode* solution(ListNode* head) {
        ListNode* nextNode, *prevNode = NULL;
        while (head) {
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }
};
