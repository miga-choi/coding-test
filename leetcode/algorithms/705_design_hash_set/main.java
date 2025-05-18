/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * boolean param_3 = obj.contains(key);
 */

class MyHashSet {
    private int[] nums;

    public MyHashSet() {
        this.nums = new int[1000001];
    }

    public void add(int key) {
        this.nums[key] = 1;
    }

    public void remove(int key) {
        this.nums[key] = 0;
    }

    public boolean contains(int key) {
        return this.nums[key] == 1;
    }
}


// Solution
class Solution_MyHashSet {
    int num[];

    public Solution_MyHashSet() {
        num = new int[31251];
    }

    // set the bit if that element is present
    public void add(int key) {
        num[getIdx(key)] |= getMask(key);
    }

    // unset the bit if a key is not present
    public void remove(int key) {
        num[getIdx(key)] &= (~getMask(key));
    }

    // check if bit corresponding to the key is set or not
    public boolean contains(int key) {
        return (num[getIdx(key)] & getMask(key)) != 0;
    }

    // idx of num[] to which this key belongs
    // for key = 37, it will give 1
    private int getIdx(int key) {
        return (key / 32);
    }

    // get mask representing the bit inside num[idx] that corresponds to given key.
    // for key = 37, it will give 00000000000000000000000000100000
    private int getMask(int key) {
        key %= 32;
        return (1 << key);
    }
}
