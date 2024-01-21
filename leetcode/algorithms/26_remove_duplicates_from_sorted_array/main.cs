public class RemoveDuplicatesFromSortedArray
{
    public int RemoveDuplicates(int[] nums)
    {
        HashSet<int> numsSet = new HashSet<int>(nums);
        int count = 0;

        foreach (int num in numsSet)
        {
            nums[count] = num;
            count++;
        }

        return numsSet.Count;
    }


    // Best Solution
    // Best Solution 1:
    public int bestSolution1(int[] nums)
    {
        int i = 1;

        foreach (int n in nums)
        {
            if (nums[i - 1] != n)
            {
                nums[i++] = n;
            }
        }

        return i;
    }

    // Best Solution 2:
    public int bestSolution2(int[] nums)
    {
        int k = 1;
        int previouse = nums[0];
        for (int i = 1; i < nums.Length; i++)
        {
            if (nums[i] != previouse)
            {
                nums[k] = nums[i];
                k++;
            }
            previouse = nums[i];
        }
        return k;
    }

    // Best Solution 3:
    public int bestSolution3(int[] nums)
    {
        HashSet<int> secondary = new HashSet<int>();
        int counter = 0;
        for (int i = 0; i < nums.Length; i++)
        {
            if (secondary.Add(nums[i]))
            {
                nums[counter++] = nums[i];
            }
        }
        return counter;
    }

    // Best Solution 4:
    public int bestSolution4(int[] nums)
    {
        int i = 0;
        for (int j = 0; j < nums.Length; j++)
        {
            nums[i++] = nums[j];
            while (j < nums.Length - 1 && nums[j] == nums[j + 1])
            {
                j++;
            }
        }
        return i;
    }
}