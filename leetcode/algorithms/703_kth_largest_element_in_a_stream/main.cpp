#include <queue>
#include <vector>
using namespace std;

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> _priorityQueue;
    int _k;
    
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for (int i = 0; i < nums.size(); i++) {
            _priorityQueue.push(nums[i]);
            if (_priorityQueue.size() > k) {
                _priorityQueue.pop();
            }
        }
    }
    
    int add(int val) {
        _priorityQueue.push(val);
        if (_priorityQueue.size() > _k) {
            _priorityQueue.pop();
        }
        return _priorityQueue.top();
    }
};


// Solution
class Solution_KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;

    Solution_KthLargest(int k, vector<int> nums) {
        size = k;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > size) {
            pq.pop();
        }
        return pq.top();
    }
};
