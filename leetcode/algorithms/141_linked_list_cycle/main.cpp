#include <cstddef>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class LinkedListCycle {
public:
    bool hasCycle(ListNode* head) {
        ListNode* node1 = head;
        ListNode* node2 = head;

        while (node2 != nullptr && node2->next != nullptr) {
            node1 = node1->next;
            node2 = node2->next->next;
            if (node1 == node2) {
                return true;
            }
        }

        return false;
    }


    // Solution
    bool solution(ListNode* head) {
        // making two pointers fast and slow and assignning them to head
        ListNode* fast = head;
        ListNode* slow = head;

        // till fast and fast-> next not reaches NULL
        // we will increment fast by 2 step and slow by 1 step
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;

            // At the point if fast and slow are at same address
            // this means linked list has a cycle in it.
            if (fast == slow) {
                return true;
            }
        }

        // if traversal reaches to NULL this means no cycle.
        return false;
    }
};
