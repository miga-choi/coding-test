#include <string>
using namespace std;

class ReverseVowelsOfAString {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.size();
        while (i < j) {
            if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
                s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                s[i] == 'o' || s[i] == 'u') {
                while (1) {
                    if (s[j] == 'A' || s[j] == 'E' || s[j] == 'I' ||
                        s[j] == 'O' || s[j] == 'U' || s[j] == 'a' ||
                        s[j] == 'e' || s[j] == 'i' || s[j] == 'o' ||
                        s[j] == 'u') {
                        char temp = s[i];
                        s[i] = s[j];
                        s[j] = temp;
                        j--;
                        break;
                    }
                    j--;
                }
            }
            i++;
        }

        return s;
    }

    // Best Solution
    string bestSolution(string s) {
        // Convert the input string to a character array.
        string word = s;
        int start = 0;
        int end = s.length() - 1;
        string vowels = "aeiouAEIOU";

        // Loop until the start pointer is no longer less than the end pointer.
        while (start < end) {
            // Move the start pointer towards the end until it points to a vowel.
            while (start < end && vowels.find(word[start]) == string::npos) {
                start++;
            }

            // Move the end pointer towards the start until it points to a vowel.
            while (start < end && vowels.find(word[end]) == string::npos) {
                end--;
            }

            // Swap the vowels found at the start and end positions.
            swap(word[start], word[end]);

            // Move the pointers towards each other for the next iteration.
            start++;
            end--;
        }

        // Return the modified string.
        return word;
    }
};
