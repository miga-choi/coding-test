#include <string>
#include <vector>
using namespace std;

class ShortestCompletingWord {
public:
    int isCompleting(vector<int> plateFreq, string word) {
        vector<int> wordFreq = vector<int>(26);

        for (int i = 0; i < word.size(); i++) {
            wordFreq[word[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (wordFreq[i] < plateFreq[i]) {
                return 0;
            }
        }

        return 1;
    }

    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> plateFreq = vector<int>(26);

        for (int i = 0; i < licensePlate.size(); i++) {
            if (isalpha(licensePlate[i])) {
                plateFreq[tolower(licensePlate[i]) - 'a']++;
            }
        }

        string shortestWord = "";
        int minLength = 15;

        for (int i = 0; i < words.size(); i++) {
            int currentLength = words[i].size();

            if (currentLength >= minLength) {
                continue;
            }

            if (isCompleting(plateFreq, words[i])) {
                minLength = currentLength;
                shortestWord = words[i];
            }
        }

        return shortestWord;
    }

    // Solution
    int primes[26] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                      43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

    unsigned long getCharProduct(string plate) {
        unsigned long product = 1L;

        for (char c : plate) {
            int index = c - 'a';
            if (0 <= index && index <= 25) {
                product *= primes[index];
            }
        }

        return product;
    }

    string solution(string licensePlate, vector<string>& words) {
        for (int i = 0; i < licensePlate.size(); i++) {
            licensePlate[i] = tolower(licensePlate[i]);
        }

        unsigned long charProduct = getCharProduct(licensePlate);

        string shortest = "aaaaaaaaaaaaaaaaaaaa"; // 16 a's

        for (string word : words) {
            if (word.size() < shortest.size() &&
                getCharProduct(word) % charProduct == 0) {
                shortest = word;
            }
        }

        return shortest;
    }
};
