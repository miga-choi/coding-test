public class LongestCommonPrefix
{
    public string LongestCommonPrefix(string[] strs)
    {
        for (int i = 0; ; i++)
        {
            if (strs[0] == "")
            {
                return "";
            }
            if (strs.Length == 1)
            {
                return strs[0];
            }
            for (int j = 0; j < strs.Length; j++)
            {
                if (i >= strs[j].Length || strs[j][i] != strs[0][i])
                {
                    return strs[0].Substring(0, i);
                }
            }
        }
    }


    // Best Solution
    // Best Solution 1:
    public string bestSolution1(string[] strs)
    {
        string shortest = ss.OrderBy(s => s.Length).First();

        for (int i = 0; i < shortest.Length; i++)
        {
            if (ss.Select(s => s[i]).Distinct().Count() > 1)
            {
                return shortest[..i];
            }
        }

        return shortest;
    }

    // Best Solution 2: StringBuilder
    public string bestSolution2(string[] strs)
    {
        int i = 0;
        StringBuilder sb = new();
        string shortest = ss.OrderBy(s => s.Length).First();

        foreach (char c in shortest)
        {
            if (ss.Any(s => s[i] != c))
            {
                break;
            }
            sb.Append(c);
            i++;
        }

        return sb.ToString();
    }

    // Best Solution 3: LINQ/tuples
    public string bestSolution3(string[] strs)
    {
        StringBuilder sb = new();
        string shortest = ss.OrderBy(s => s.Length).First();

        foreach (var (c, i) in shortest.Select((c, i) => (c, i)))
        {
            if (ss.Any(s => s[i] != c))
            {
                break;
            }
            sb.Append(c);
        }

        return sb.ToString();
    }

    // Best Solution 4:
    public string bestSolution4(string[] strs)
    {
        if (strs.Length == 1)
        {
            return strs[0];
        }

        var prefixString = "";

        if (strs == null || strs.Length == 0)
        {
            return prefixString;
        }

        // Go through all the letters of the first word
        for (int i = 0; i < strs[0].Length; i++)
        {
            // Go through each of the remaining words
            foreach (string str in strs)
            {
                // If i is higher then the length of the word
                // there is no longer a prefix to match
                if (i > str.Length - 1)
                {
                    return prefixString;
                }

                // If the i-th letter of the string doesn't match the i-th 
                // letter of the first word we've reached the end of the
                // common prefix
                if (strs[0][i] != str[i])
                {
                    return prefixString;
                }
            }

            // If we make it through the inner foreach all of the 
            prefixString += strs[0][i];
        }

        return prefixString;
    }
}