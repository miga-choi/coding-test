import java.util.Arrays;

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */

class MyHashMap {
    private final int[] nums = new int[1000001];

    public MyHashMap() {
        Arrays.fill(this.nums, -1);
    }

    public void put(int key, int value) {
        this.nums[key] = value;
    }

    public int get(int key) {
        return this.nums[key];
    }

    public void remove(int key) {
        this.nums[key] = -1;
    }
}


// Solution
// Solution 1: Array
class Solution1_MyHashMap {
    int[] data;

    public Solution1_MyHashMap() {
        data = new int[1000001];
        Arrays.fill(data, -1);
    }

    public void put(int key, int val) {
        data[key] = val;
    }

    public int get(int key) {
        return data[key];
    }

    public void remove(int key) {
        data[key] = -1;
    }
}

// Solution 2: Hash
class ListNode {
    int key, val;
    ListNode next;

    public ListNode(int key, int val, ListNode next) {
        this.key = key;
        this.val = val;
        this.next = next;
    }
}

class Solution2_MyHashMap {
    static final int size = 19997;
    static final int mult = 12582917;
    ListNode[] data;

    public Solution2_MyHashMap() {
        this.data = new ListNode[size];
    }

    private int hash(int key) {
        return (int) ((long) key * mult % size);
    }

    public void put(int key, int val) {
        remove(key);
        int h = hash(key);
        ListNode node = new ListNode(key, val, data[h]);
        data[h] = node;
    }

    public int get(int key) {
        int h = hash(key);
        ListNode node = data[h];

        for (; node != null; node = node.next) {
            if (node.key == key) {
                return node.val;
            }
        }

        return -1;
    }

    public void remove(int key) {
        int h = hash(key);
        ListNode node = data[h];

        if (node == null) {
            return;
        }

        if (node.key == key) {
            data[h] = node.next;
        } else {
            for (; node.next != null; node = node.next) {
                if (node.next.key == key) {
                    node.next = node.next.next;
                    return;
                }
            }
        }
    }
}
