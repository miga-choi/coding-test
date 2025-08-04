#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class RestoreTheArrayFromAdjacentPairs {
public:
    /**
     * Graph & Hash Map & Vector
     * - Time Complexity: O(N)
     * - Space Complexity: O(N)
     */
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adjacentMap;

        for (const vector<int>& adjacentPair : adjacentPairs) {
            adjacentMap[adjacentPair[0]].push_back(adjacentPair[1]);
            adjacentMap[adjacentPair[1]].push_back(adjacentPair[0]);
        }

        int start;
        for (const pair<int, vector<int>>& mapPair : adjacentMap) {
            if (mapPair.second.size() == 1) {
                start = mapPair.first;
                break;
            }
        }

        int length = adjacentPairs.size() + 1;
        vector<int> result;

        int curr = start;
        int prev = -100001;

        for (int i = 0; i < length; i++) {
            result.push_back(curr);

            const vector<int>& neighbors = adjacentMap[curr];

            int next;
            if (neighbors.size() == 1 || neighbors[0] != prev) {
                next = neighbors[0];
            } else {
                next = neighbors[1];
            }

            prev = curr;
            curr = next;
        }

        return result;
    }


    // Solution
    vector<int> solution(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> ps;

        for (auto& p : adjacentPairs) {
            ps[p[0]].push_back(p[1]);
            ps[p[1]].push_back(p[0]);
        }

        vector<int> res;
        for (auto& p : ps) {
            if (p.second.size() == 1) {
                res.push_back(p.first);
                res.push_back(p.second[0]);
                break;
            }
        }

        while (res.size() < adjacentPairs.size() + 1) {
            auto tail = res.back(), prev = res[res.size() - 2];
            auto& next = ps[tail];

            if (next[0] != prev) {
                res.push_back(next[0]);
            } else {
                res.push_back(next[1]);
            }
        }

        return res;
    }
};
