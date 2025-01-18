#include <vector>
using namespace std;

class ConstructTheRectangle {
public:
    vector<int> constructRectangle(int area) {
        vector<int> result = {area, 1};
        int diff = area;
        for (int i = 1; i <= sqrt(area); i++) {
            if (!(area % i)) {
                if (area / i - i < diff) {
                    result[0] = area / i;
                    result[1] = i;
                }
            }
        }
        return result;
    }

    // Best Solution
    vector<int> bestSolution(int area) {
        int w = (int)sqrt(area);
        while (area % w != 0) {
            w--;
        }
        return {area / w, w};
    }
};
