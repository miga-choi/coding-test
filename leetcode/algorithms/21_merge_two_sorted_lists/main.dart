class ListNode {
  int val;
  ListNode? next;
  ListNode([this.val = 0, this.next]);
}

class MergeTwoSortedLists {
  ListNode? mergeTwoLists(ListNode? list1, ListNode? list2) {
    if (list1 == null) {
      return list2;
    } else if (list2 == null) {
      return list1;
    } else {
      ListNode result = ListNode();
      ListNode current = result;

      while (list1 != null || list2 != null) {
        if (list1 != null && list2 != null) {
          if (list1.val > list2.val) {
            current.next = list2;
            list2 = list2.next;
          } else {
            current.next = list1;
            list1 = list1.next;
          }
        } else if (list1 != null) {
          current.next = list1;
          list1 = list1.next;
        } else if (list2 != null) {
          current.next = list2;
          list2 = list2.next;
        }
        current = current.next!;
      }

      return result.next;
    }
  }


  // Solution
  ListNode? solution(ListNode? list1, ListNode? list2) {
    if (list1 == null) {
      return list2;
    }
    if (list2 == null) {
      return list1;
    }

    if (list1.val < list2.val) {
      list1.next = solution(list1.next, list2);
      return list1;
    } else {
      list2.next = solution(list1, list2.next);
      return list2;
    }
  }
}
