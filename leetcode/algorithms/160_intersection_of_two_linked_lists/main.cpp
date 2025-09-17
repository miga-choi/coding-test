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
     * - Time Complexity: O(M * N)
     * - Space Complexity: O(1)
     */
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        while (headA) {
            ListNode* dummyB = headB;

            while (dummyB) {
                if (headA == dummyB) {
                    return headA;
                }
                dummyB = dummyB->next;
            }

            headA = headA->next;
        }
        
        return headA;
    }


    // Solution
    /**
     * Two-Pointer
     * - Time Complexity: O(M + N)
     * - Space Complexity: O(1)
     */
    ListNode* solution(ListNode* headA, ListNode* headB) {
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        while (ptrA != ptrB) {
            ptrA = ptrA ? ptrA->next : headB;
            ptrB = ptrB ? ptrB->next : headA;
        }

        return ptrA;
    }
};
