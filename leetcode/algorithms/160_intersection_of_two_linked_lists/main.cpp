#include<cstddef>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class IntersectionOfTwoLinkedLists {
public:
    /**
     * Two-Pointer
     *
     * Complexities:
     *   N - Number of Nodes in `headA`
     *   M - Number of Nodes in `headB`
     *   - Time Complexity: O(M + N)
     *   - Space Complexity: O(1)
     */
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        while (ptrA != ptrB) {
            ptrA = (ptrA == nullptr) ? headB : ptrA->next;
            ptrB = (ptrB == nullptr) ? headA : ptrB->next;
        }

        return ptrA;
    }


    // Solution
    /**
     * Two-Pointer
     *
     * Complexities:
     *   N - Number of Nodes in `headA`
     *   M - Number of Nodes in `headB`
     *   - Time Complexity: O(M + N)
     *   - Space Complexity: O(1)
     */
    ListNode* solution(ListNode* headA, ListNode* headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        ListNode* pA = headA;
        ListNode* pB = headB;

        while (pA != pB) {
            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
        }

        return pA;
    }
};
