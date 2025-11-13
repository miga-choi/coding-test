#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class GroupAnagrams {
public:
    /**
     * Complexities:
     *   N - size of strs
     *   K - max size of strings in strs
     *   - Time Complexity: O(N * K * logᴷ)
     *   - Space Complexity: O(N * K)
     */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;

        unordered_map<string, vector<string>> str_map;

        for (string str : strs) {
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());
            str_map[sorted_str].push_back(str);
        }

        for (const auto& pair : str_map) {
            result.push_back(pair.second);
        }

        return result;
    }


    // Solution
    /**
     * Complexities:
     *   N - size of strs
     *   K - max size of strings in strs
     *   - Time Complexity: O(N * K * logᴷ)
     *   - Space Complexity: O(N * K)
     */
    vector<vector<string>> solution(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for (const string& original_str : strs) {
            string sorted_key = original_str;
            sort(sorted_key.begin(), sorted_key.end());

            map[sorted_key].push_back(original_str);
        }

        vector<vector<string>> result;
        for (const auto& pair : map) {
            result.push_back(pair.second);
        }

        return result;
    }
};
