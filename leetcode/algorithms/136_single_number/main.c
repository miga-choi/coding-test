int singleNumber(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result = result ^ nums[i];
    }
    return result;
}


// Solution
int solution(int* nums, int numsSize) {
    // Initialize the unique number...
    int uniqNum = 0;

    // TRaverse all elements through the loop...
    for (int idx = 0; idx < numsSize; idx++) {
        // Concept of XOR...
        uniqNum = uniqNum ^ nums[idx];
    }

    // Return the unique number...
    return uniqNum;
}
