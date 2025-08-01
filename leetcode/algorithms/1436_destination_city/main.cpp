#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class DestinationCity {
public:
    /**
     * Set
     * Time Complexity: O(N)
     * Space Complexity: O(N)
     */
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> cities;

        for (const vector<string>& path : paths) {
            cities.insert(path[0]);
        }

        for (const vector<string>& path : paths) {
            const string& destination = path[1];
            if (cities.count(destination) == 0) {
                return destination;
            }
        }

        return "";
    }

    // Solution
    string solution(vector<vector<string>>& paths) {
        unordered_set<string> cities;

        // Collect outgoing cities
        for (const auto& path : paths) {
            cities.insert(path[0]);
        }

        // Find destination city with no outgoing path
        for (const auto& path : paths) {
            const string& dest = path[1];
            if (cities.find(dest) == cities.end()) {
                return dest;
            }
        }

        return "";
    }
};
