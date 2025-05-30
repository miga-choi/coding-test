#include <vector>
using namespace std;

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

class MyHashMap {
private:
    vector<int> nums;

public:
    MyHashMap() {
        nums = vector(1e6 + 1, -1);
    }

    void put(int key, int value) {
        nums[key] = value;
    }

    int get(int key) {
        return nums[key];
    }

    void remove(int key) {
        nums[key] = -1;
    }
};


// Solution
// Solution 1: Array
class Solution1_MyHashMap {
public:
    int data[1000001];

    Solution1_MyHashMap() {
        fill(data, data + 1000001, -1);
    }

    void put(int key, int val) {
        data[key] = val;
    }

    int get(int key) {
        return data[key];
    }

    void remove(int key) {
        data[key] = -1;
    }
};

// Solution 2: Hash
struct Node {
public:
    int key, val;
    Node* next;
    Node(int k, int v, Node* n) {
        key = k;
        val = v;
        next = n;
    }
};

class Solution2_MyHashMap {
public:
    const static int size = 19997;
    const static int mult = 12582917;
    Node* data[size] = {};

    int hash(int key) {
        return (int)((long)key * mult % size);
    }

    void put(int key, int val) {
        remove(key);
        int h = hash(key);
        Node* node = new Node(key, val, data[h]);
        data[h] = node;
    }

    int get(int key) {
        int h = hash(key);
        Node* node = data[h];
        for (; node != NULL; node = node->next) {
            if (node->key == key) {
                return node->val;
            }
        }
        return -1;
    }

    void remove(int key) {
        int h = hash(key);
        Node* node = data[h];
        if (node == NULL) {
            return;
        }
        if (node->key == key) {
            data[h] = node->next;
            delete node;
        } else {
            for (; node->next != NULL; node = node->next) {
                if (node->next->key == key) {
                    Node* temp = node->next;
                    node->next = temp->next;
                    delete temp;
                    return;
                }
            }
        }
    }
};
