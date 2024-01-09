public class RomanToInteger
{
    public int RomanToInt(string s)
    {
        Dictionary<char, int> romanMap = new Dictionary<char, int>(){
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

        int result = 0;

        for (int i = 0; i < s.Length - 1; i++)
        {
            if (romanMap[s[i]] < romanMap[s[i + 1]])
            {
                result -= romanMap[s[i]];
            }
            else
            {
                result += romanMap[s[i]];
            }
        }
        result += romanMap[s[s.Length - 1]];

        return result;
    }


    // Best Solution
    // Best Solution 1:
    public int bestSolution1(string s)
    {
        var chars = s.ToCharArray();
        var result = 0;
        var currentValue = 0;
        for (var i = 0; i < chars.Length - 1; i++)
        {
            currentValue = RomanNumerals(chars[i]);
            result += (RomanNumerals(chars[i + 1]) > currentValue ? -1 : 1) * currentValue;
        }

        return result + RomanNumerals(chars[chars.Length - 1]);
    }

    public int RomanNumerals(char c)
    {
        switch (c)
        {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        };
        return 0;
    }

    // Best Solution 2:
    public int bestSolution2(string s)
    {
        var map = new Dictionary<char, int>();
        map.Add('I', 1);
        map.Add('V', 5);
        map.Add('X', 10);
        map.Add('L', 50);
        map.Add('C', 100);
        map.Add('D', 500);
        map.Add('M', 1000);
        int sum = 0;
        int last = 0;
        for (int i = s.Length - 1; i >= 0; i--)
        {
            int current = map[s[i]];
            if (current < last)
            {
                sum -= current;
            }
            else
            {
                sum += current;
            }

            last = current;
        }
        return sum;
    }

    // Best Solution 3:
    public int bestSolution3(string s)
    {
        int[] Key = new int[] { 8, 21, 23, 11, 2, 3, 12 };
        int[] value = new int[] { 1, 5, 10, 50, 100, 500, 1000 };
        int res = 0, tKey = 0;
        for (int i = s.Length - 1; i >= 0; i--)
        {
            int cKey = Array.IndexOf(Key, (s[i] - 'A'));
            if (tKey > cKey) res -= Math.Abs(value[cKey]);
            else res += value[cKey];
            tKey = cKey;
        }
        return res;
    }

    // Best Solution 4:
    public int bestSolution4(string s)
    {
        var map = new Dictionary<Char, int> {
            { 'I', 1 },
            { 'V', 5 },
            { 'X', 10 },
            { 'L', 50 },
            { 'C', 100 },
            { 'D', 500 },
            { 'M', 1000 },
        };
        int sum = map[s.LastOrDefault()];
        for (int i = s.Length - 2; i >= 0; --i)
        {
            if (map[s[i]] < map[s[i + 1]]) sum -= map[s[i]];
            else sum += map[s[i]];
        }
        return sum;
    }

    // Best Solution 5:
    public int bestSolution5(string s)
    {
        var map = new Dictionary<Char, int> {
        { 'I' , 1 }, { 'V' , 5 }, { 'X' , 10 }, { 'L' , 50 }, { 'C' , 100 }, { 'D' , 500 }, { 'M' , 1000 } };
        int sum = 0;
        s = s.Replace("IV", "IIII").Replace("IX", "VIIII")
            .Replace("XL", "XXXX").Replace("XC", "LXXXX")
            .Replace("CD", "CCCC").Replace("CM", "DCCCC");
        foreach (var c in s) sum += map[c];
        return sum;
    }
}