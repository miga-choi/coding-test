public class LengthOfLastWord
{
    public int LengthOfLastWord(string s)
    {
        String[] sArray = s.Split(" ");
        for (int i = sArray.Length - 1; i >= 0; i--)
        {
            if (sArray[i].Length > 0)
            {
                return sArray[i].Length;
            }
        }
        return 0;
    }


    // Best Solution
    // Best Solution 1:
    public int bestSolution1(string s)
    {
        int res = 0;
        for (int i = s.Length - 1; i >= 0;)
        {
            if (s[i--] != ' ')
            {
                res++;
            }
            else if (res > 0)
            {
                return res;
            }
        }
        return res;
    }

    // Best Solution 2:
    public int bestSolution2(string s)
    {
        return (s.TrimEnd()).Split(' ').Last().Length;
    }
}