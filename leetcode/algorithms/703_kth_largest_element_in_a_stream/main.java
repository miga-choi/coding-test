import java.util.PriorityQueue;

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */

class KthLargest {
    final private PriorityQueue<Integer> priorityQueue;
    final private int k;

    public KthLargest(int k, int[] nums) {
        this.priorityQueue = new PriorityQueue<Integer>(k, null);
        this.k = k;
        for (int num : nums) {
            add(num);
        }
    }

    public int add(int val) {
        if (this.priorityQueue.size() < k) {
            this.priorityQueue.offer(val);
        } else {
            if (this.priorityQueue.peek() < val) {
                this.priorityQueue.poll();
                this.priorityQueue.offer(val);
            }
        }
        return this.priorityQueue.peek();
    }
}


// Solution
class Solution_KthLargest {
    final PriorityQueue<Integer> q;
    final int k;

    public Solution_KthLargest(int k, int[] a) {
        this.k = k;
        q = new PriorityQueue<>(k);
        for (int n : a) {
            add(n);
        }
    }

    public int add(int n) {
        if (q.size() < k) {
            q.offer(n);
        } else if (q.peek() < n) {
            q.poll();
            q.offer(n);
        }
        return q.peek();
    }
}
