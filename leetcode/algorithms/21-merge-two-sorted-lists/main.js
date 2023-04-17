/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
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
