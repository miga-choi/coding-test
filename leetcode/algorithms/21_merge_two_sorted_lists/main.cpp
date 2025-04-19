#include <stdio.h>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class MergeTwoSortedLists {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode result;
        ListNode* currentNode = &result;

        if (list1 == NULL && list2 == NULL) {
            return NULL;
        }

        while (list1 != NULL || list2 != NULL) {
            if (list1 != NULL && list2 != NULL) {
                if (list1->val > list2->val) {
                    currentNode->next = list2;
                    list2 = list2->next;
                } else {
                    currentNode->next = list1;
                    list1 = list1->next;
                }
            } else if (list1 != NULL) {
                currentNode->next = list1;
                list1 = list1->next;
            } else {
                currentNode->next = list2;
                list2 = list2->next;
            }
            currentNode = currentNode->next;
        }

        return result.next;
    }


    // Solution
    // Solution 1: RECURSIVE
    ListNode* solution1(ListNode* list1, ListNode* list2) {
        // if list1 happen to be NULL
        // we will simply return list2.
        if (list1 == NULL) {
            return list2;
        }

        // if list2 happen to be NULL
        // we will simply return list1.
        if (list2 == NULL) {
            return list1;
        }

        if (list1->val <= list2->val) {
            // if value pointend by l1 pointer is less than equal to value pointed by l2 pointer
            // we wall call recursively l1 -> next and whole l2 list.
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            // we will call recursive l1 whole list and l2 -> next
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }

    // Solution 2: ITERATIVE
    ListNode* solution2(ListNode* list1, ListNode* list2) {
        // if list1 happen to be NULL
        // we will simply return list2.
        if (list1 == NULL) {
            return list2;
        }

        // if list2 happen to be NULL
        // we will simply return list1.
        if (list2 == NULL) {
            return list1;
        }

        ListNode* ptr = list1;
        if (list1->val > list2->val) {
            ptr = list2;
            list2 = list2->next;
        } else {
            list1 = list1->next;
        }
        ListNode* curr = ptr;

        // till one of the list doesn't reaches NULL
        while (list1 && list2) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        // adding remaining elements of bigger list.
        if (!list1) {
            curr->next = list2;
        } else {
            curr->next = list1;
        }

        return ptr;
    }
};
