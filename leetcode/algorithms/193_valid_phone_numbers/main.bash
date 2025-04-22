# Read from the file file.txt and output all valid phone numbers to stdout.
grep -E '^([0-9]{3}-[0-9]{3}-[0-9]{4})$|^(\([0-9]{3}\) [0-9]{3}-[0-9]{4})$' file.txt;


# Solution
# Solution 1
# this is a grep command accepting two regular expressions
#   1 .^[0-9]\{3\}\-[0-9]\{3\}\-[0-9]\{4\}$
#   2 .^([0-9]\{3\}) [0-9]\{3\}\-[0-9]\{4\}$
# 
# The construction is as follows
#   ^: indicates the starting of the string
#   $: indicates the end of the string
#   [0-9]\{3\} : represent 3 numbers (\{3\}) between the range 0-9 ([0-9] a digit in the range)
#   \: suppresses the specialness of the character
#   -e: to include multiple regex
grep -e "^[0-9]\{3\}\-[0-9]\{3\}\-[0-9]\{4\}$" -e "^([0-9]\{3\}) [0-9]\{3\}\-[0-9]\{4\}$" file.txt

# Solution 2
# Common syntax explained:
#   ^ Start of a line (not just within a line, ex 112-122-2313 not 022121-112-2313)
#   [0-9] regex expression to represent any digit between 0 and 9.
#   \d any digit (Perl-flavoured regular expression) Note the compiler uses GNU/Linux so to use \d use the -P tag
#   {3} repeated exactly 3 times, {4} repeated 4 times ect, hence [0-9]{3} means three numbers from 0-9.
#   $ end of a line
#   | or expression
#   () used to group expressions
#   \( or\) used for literal parentheses
#   
# Solution 2-1: Using a grep search with the extended regular expressions.
#   -E Extended regular expressions same as egrep
grep -E '^(\([0-9]{3}\) [0-9]{3}-[0-9]{4})$|^([0-9]{3}-[0-9]{3}-[0-9]{4})$' file.txt

# Solution 2-2: Using a grep search with the extended regular expressions.
#   -E Extended regular expressions same as egrep
egrep '^(\([0-9]{3}\) [0-9]{3}-[0-9]{4})$|^([0-9]{3}-[0-9]{3}-[0-9]{4})$' file.txt

# Solution 3: Using grep with Perl-flavoured regular expression
grep -P '^(\(\d{3}\) |\d{3}-)\d{3}-\d{4}$' file.txt

# Solution 4: Using an awk search with regex values
awk '/^((\([0-9]{3}\) |[0-9]{3}-)[0-9]{3}-[0-9]{4})$/' file.txt
