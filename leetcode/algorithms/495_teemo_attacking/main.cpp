#include <vector>
using namespace std;

class TeemoAttacking {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = 0;
        for (int i = 1; i < timeSeries.size(); i++) {
            if (timeSeries.at(i) > timeSeries.at(i - 1) + duration) {
                total += duration;
            } else {
                total += timeSeries.at(i) - timeSeries.at(i - 1);
            }
        }
        return total + duration;
    }

    // Best Solution
    int bestSolution(vector<int>& timeSeries, int duration) {
        int res = 0;
        for (int i = 0; i < timeSeries.size() - 1; i++) {
            if (timeSeries[i + 1] - timeSeries[i] < duration) {
                res += timeSeries[i + 1] - timeSeries[i];
            } else {
                res += duration;
            }
        }
        return res + duration;
    }
};
