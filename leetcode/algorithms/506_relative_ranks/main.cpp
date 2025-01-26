#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class RelativeRanks {
public:
    vector<string> findRelativeRanks(vector<int> &score) {
        vector<string> result(score.size());
        vector<int> sortedScore = score;

        for (int i = 0; i < sortedScore.size() - 1; i++) {
            for (int j = i + 1; j < sortedScore.size(); j++) {
                if (sortedScore[j] > sortedScore[i]) {
                    int temp = sortedScore[i];
                    sortedScore[i] = sortedScore[j];
                    sortedScore[j] = temp;
                }
            }
        }

        for (int i = 0; i < score.size(); i++) {
            if (score[i] == sortedScore[0]) {
                result[i] = "Gold Medal";
            } else if (score[i] == sortedScore[1]) {
                result[i] = "Silver Medal";
            } else if (score[i] == sortedScore[2]) {
                result[i] = "Bronze Medal";
            } else {
                for (int j = 3; j < score.size(); j++) {
                    if (score[i] == sortedScore[j]) {
                        result[i] = to_string(j + 1);
                    }
                }
            }
        }

        return result;
    }

    // Solution 1: Sorting and Mapping
    vector<string> solution1(vector<int> &score) {
        vector<int> sortedScore = score;
        sort(sortedScore.begin(), sortedScore.end(), greater<int>());
        vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        unordered_map<int, string> rankMapping;
        for (int i = 0; i < sortedScore.size(); i++) {
            if (i < 3) {
                rankMapping[sortedScore[i]] = medals[i];
            } else {
                rankMapping[sortedScore[i]] = to_string(i + 1);
            }
        }
        vector<string> result;
        for (int s : score) {
            result.push_back(rankMapping[s]);
        }
        return result;
    }

    // Solution 2: Priority Queue
    vector<string> solution2(vector<int> &score) {
        int N = score.size();

        // Create a max heap of pairs (score, index)
        priority_queue<pair<int, int>> heap;
        for (int i = 0; i < N; i++) {
            heap.push({score[i], i});
        }

        // Assign ranks to athletes
        vector<string> rank(N);
        int place = 1;
        while (!heap.empty()) {
            int originalIndex = heap.top().second;
            heap.pop();
            if (place == 1) {
                rank[originalIndex] = "Gold Medal";
            } else if (place == 2) {
                rank[originalIndex] = "Silver Medal";
            } else if (place == 3) {
                rank[originalIndex] = "Bronze Medal";
            } else {
                rank[originalIndex] = to_string(place);
            }
            place++;
        }
        return rank;
    }

    // Solution 3: Array as Map
    int findMax(vector<int> &score) {
        int maxScore = 0;
        for (int s : score) {
            if (s > maxScore) {
                maxScore = s;
            }
        }
        return maxScore;
    }

    vector<string> solution3(vector<int> &score) {
        int N = score.size();

        // Add the original index of each score to the array
        // Where the score is the key
        int M = findMax(score);
        vector<int> scoreToIndex(M + 1, 0);
        for (int i = 0; i < N; i++) {
            scoreToIndex[score[i]] = i + 1;
        }

        const vector<string> MEDALS = {"Gold Medal", "Silver Medal", "Bronze Medal"};

        // Assign ranks to athletes
        vector<string> rank(N);
        int place = 1;
        for (int i = M; i >= 0; i--) {
            if (scoreToIndex[i] != 0) {
                int originalIndex = scoreToIndex[i] - 1;
                if (place < 4) {
                    rank[originalIndex] = MEDALS[place - 1];
                } else {
                    rank[originalIndex] = to_string(place);
                }
                place++;
            }
        }
        return rank;
    }
};
