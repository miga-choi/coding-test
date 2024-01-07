public class PalindromeNumber
{
    public bool IsPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }

        int origin = x;
        int reverse = 0;
        while (x > 0)
        {
            int res = x % 10;
            x /= 10;
            reverse = reverse * 10 + res;
        }

        return reverse == origin;
    }

    // Best Solution
    public bool bestSolution(int x)
    {
        int r = 0, c = x;
        while (c > 0)
        {
            r = r * 10 + c % 10;
            c /= 10;
        }
        return r == x;
    }
}