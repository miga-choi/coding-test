/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeTwoLists = function (list1, list2) {
  if (!list1 && !list2) {
    return null;
  }
  if (!list1) {
    return list2;
  } else if (!list2) {
    return list1;
  } else {
    const valArray = [];
    do {
      valArray.push(list1.val);
      list1 = list1.next;
    } while (list1);
    do {
      valArray.push(list2.val);
      list2 = list2.next;
    } while (list2);
    valArray.sort((prev, next) => prev - next);
    console.log(valArray);
    const listNodeArray = [];
    for (const val of valArray) {
      listNodeArray.push(new ListNode(val));
    }
    for (let i = 0; i < listNodeArray.length - 1; i++) {
      listNodeArray[i].next = listNodeArray[i + 1];
    }
    return listNodeArray[0];
  }
};

// Best Solution
// Best Solution 1:
var bestSolution1 = function (l1, l2) {
  if (!l1) {
    return l2;
  } else if (!l2) {
    return l1;
  } else if (l1.val <= l2.val) {
    l1.next = mergeTwoLists(l1.next, l2);
    return l1;
  } else {
    l2.next = mergeTwoLists(l1, l2.next);
    return l2;
  }
};

// Best Solution 2:
var bestSolution12 = function (l1, l2) {
  var mergedHead = { val: -1, next: null }, crt = mergedHead;
  while (l1 && l2) {
    if (l1.val > l2.val) {
      crt.next = l2;
      l2 = l2.next;
    } else {
      crt.next = l1;
      l1 = l1.next;
    }
    crt = crt.next;
  }
  crt.next = l1 || l2;

  return mergedHead.next;
};
