/**
 * Three Pointers: from end to begin
 * - Time Complexity: O(M+N)
 * - Time Complexity: O(1)
 */
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int p1 = m - 1;
    int p2 = n - 1;
    int p = nums1Size - 1;

    while (p2 >= 0) {
        if (p1 >= 0 && nums1[p1] > nums2[p2]) {
            nums1[p] = nums1[p1];
            p1--;
        } else {
            nums1[p] = nums2[p2];
            p2--;
        }
        p--;
    }
}


// Solution
// Solution 1: Two Pointers
void solution1(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    // Initialize i and j to store indices of the last element of 1st and 2nd array respectively...
    int i = m - 1;
    int j = n - 1;

    // Create a loop until either of i or j becomes zero...
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[i + j + 1] = nums1[i];
            i--;
        } else {
            nums1[i + j + 1] = nums2[j];
            j--;
        }
    }

    // While j does not become zero...
    while (j >= 0) {
        nums1[i + j + 1] = nums2[j];
        j--;
    }
}

// Solution 2: Two Pointers
void solution2(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            k--;
            i--;
        } else {
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
    while (j >= 0) {
        nums1[k] = nums2[j];
        k--;
        j--;
    }
}
