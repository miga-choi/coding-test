#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode result;
    struct ListNode* currentNode = &result;

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
// Solution 1:
struct ListNode* bestSolution1(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode head;
    struct ListNode* h = &head;

    if (list1 == NULL && list2 == NULL) {
        return NULL;
    }

    while (list1 && list2) {
        if (list1->val < list2->val) {
            h->next = list1;
            list1 = list1->next;
            h = h->next;
        } else {
            h->next = list2;
            list2 = list2->next;
            h = h->next;
        }
    }

    if (list1) {
        h->next = list1;
    }
    if (list2) {
        h->next = list2;
    }

    return head.next;
}

// Solution 2:
struct ListNode* solution2(struct ListNode* list1, struct ListNode* list2) {
    if (!list1) {
        return list2;
    }
    if (!list2) {
        return list1;
    }
    struct ListNode* head = list1->val <= list2->val ? list1 : list2;
    head->next = list1->val <= list2->val ? mergeTwoLists(list1->next, list2) : mergeTwoLists(list1, list2->next);
    return head;
}

// Solution 3:
struct ListNode* solution3(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* res = NULL;
    if (list1 == NULL)
    {
        return list2;
    } else if (list2 == NULL) {
        return list1;
    }
    if (list1->val <= list2->val)
    {
        res = list1;
        res->next = mergeTwoLists(list1->next, list2);
    } else {
        res = list2;
        res->next = mergeTwoLists(list1, list2->next);
    }
    return res;
}
