class NumberOf1Bits
{
public:
    int hammingWeight(int n)
    {
        int count = 0;

        for (size_t i = 0; i < 32; i++)
        {
            if (n & 1)
            {
                count++;
            }
            n = n >> 1;
        }

        return count;
    }

    // Best Solution
    int bestSolution(int n)
    {
        int count = 0;

        while (n)
        {
            n &= (n - 1);
            count++;
        }

        return count;
    }
};