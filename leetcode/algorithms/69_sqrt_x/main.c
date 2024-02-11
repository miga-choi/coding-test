int mySqrt(int x)
{
    if (x == 0)
    {
        return 0;
    }

    long low = 1;
    long high = x;

    while (low <= high)
    {
        long mid = (low + high) / 2;

        if (mid == x / mid)
        {
            return (int)mid;
        }
        else if (mid > x / mid)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return (int)high;
}


// Best Solution
// Best Solution 1:
int bestSolution1(int x)
{
    long r = x;
    while (r * r > x)
    {
        r = (r + x / r) / 2;
    }
    return r;
}

// Best Solution 2:
int bestSolution2(int x)
{
    long long s = 0, e = x, ans, mid; // long long due to some of test cases overflows integer limit.
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (mid * mid == x)
        {
            return mid; // if the 'mid' value ever gives the result, we simply return it.
        }
        else if (mid * mid < x)
        {
            s = mid + 1; // if 'mid' value encounterted gives lower result, we simply discard all the values lower than mid.
            ans = mid;   // an extra pointer 'ans' is maintained to keep track of only lowest 'mid' value.
        }
        else
        {
            e = mid - 1; // if 'mid' value encountered gives greater result, we simply discard all the values greater than mid.
        }
    }
    return ans;
}

// Best Solution 3:
int bestSolution3(int x)
{
    long long i = 0;
    while (i * i <= x)
    {
        i++;
    }
    return i - 1;
}