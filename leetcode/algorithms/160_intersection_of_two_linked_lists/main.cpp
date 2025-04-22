#include<cstddef>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class IntersectionOfTwoLinkedLists {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        while (headA != nullptr) {
            ListNode* temp = headB;
            while (temp != nullptr) {
                if (temp == headA) {
                    return temp;
                }
                temp = temp->next;
            }
            headA = headA->next;
        }
        return nullptr;
    }


    // Solution
    ListNode* solution(ListNode* headA, ListNode* headB) {
        struct ListNode* p1 = headA;
        struct ListNode* p2 = headB;

        if (p1 == nullptr || p2 == nullptr) {
            return nullptr;
        }

        while (p1 != nullptr && p2 != nullptr && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;

            // Any time they collide or reach end together without colliding
            // then return any one of the pointers.
            if (p1 == p2) {
                return p1;
            }

            // If one of them reaches the end earlier then reuse it
            // by moving it to the beginning of other list.
            // Once both of them go through reassigning,
            // they will be equidistant from the collision point.
            if (p1 == nullptr) {
                p1 = headB;
            }
            if (p2 == nullptr) {
                p2 = headA;
            }
        }

        return p1;
    }
};
