using System;
using System.Collections.Generic;

public class Solution
{
    public int[] TwoSum(int[] nums, int target)
    {
        for (int i = 0; i < nums.Length - 1; i++)
        {
            for (int j = i + 1; j < nums.Length; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return [i, j];
                }
            }
        }

        return [];
    }


    // Best Solution
    // Best Solution 1:
    public int[] bestSolution1(int[] nums, int target)
    {
        Dictionary<int, int> seen = new Dictionary<int, int>();
        for (int i = 0; i < nums.Length; i++)
        {
            //if we've seen the matching number to our number
            if (seen.ContainsKey(target - nums[i]))
            {
                //then return the matching numbers index and our own
                return new int[] { seen[target - nums[i]], i };
            }
            //otherwise add our value to the dictionary and continue
            //if we've already seen this value we can ignore it since both indexes would be valid.
            if (!seen.ContainsKey(nums[i]))
            {
                seen.Add(nums[i], i);
            }

        }
        //Since they state there is always a solution to the problem we should never actually hit this.
        return null;
    }

    // Best Solution 2:
    public int[] bestSolution2(int[] nums, int target)
    {
        Dictionary<int, int> map = new Dictionary<int, int>();

        for (int i = 0; i < nums.Length; i++)
        {
            int complement = target - nums[i];
            if (map.ContainsKey(complement))
            {
                return new int[] { map[complement], i };
            }

            map[nums[i]] = i;
        }
        return new int[0];
    }
}