void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    for (int i = 0; i < n; i++)
    {
        nums1[m + i] = nums2[i];
    }

    for (int i = 0; i < m + n; i++)
    {
        for (int j = i + 1; j < m + n; j++)
        {
            if (nums1[i] > nums1[j])
            {
                int temp = nums1[i];
                nums1[i] = nums1[j];
                nums1[j] = temp;
            }
        }
    }
}


// Best Solution
// Best Solution 1: Two Pointers
void bestSolution1(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    // Initialize i and j to store indices of the last element of 1st and 2nd array respectively...
    int i = m - 1;
    int j = n - 1;
    // Create a loop until either of i or j becomes zero...
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[i + j + 1] = nums1[i];
            i--;
        }
        else
        {
            nums1[i + j + 1] = nums2[j];
            j--;
        }
    }
    // While j does not become zero...
    while (j >= 0)
    {
        nums1[i + j + 1] = nums2[j];
        j--;
    }
}

// Best Solution 2: Two Pointers
void bestSolution2(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k] = nums1[i];
            k--;
            i--;
        }
        else
        {
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }
    while (j >= 0)
    {
        nums1[k] = nums2[j];
        k--;
        j--;
    }
}
