#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class MinimumIndexSumOfTwoLists {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> result;
        int minIndex = list1.size() + list2.size();
        vector<int> intArray(list1.size(), minIndex);

        for (int i = 0; i < list1.size(); i++) {
            for (int j = 0; j < list2.size(); j++) {
                if (list1.at(i).compare(list2.at(j)) == 0) {
                    int indexSum = i + j;
                    intArray.at(i) = indexSum;
                    if (indexSum < minIndex) {
                        minIndex = indexSum;
                    }
                }
            }
        }

        for (int i = 0; i < list1.size(); i++) {
            if (intArray.at(i) == minIndex) {
                result.push_back(list1.at(i));
            }
        }

        return result;
    }

    // Solution
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        unordered_map<string, int> m;
        int min = INT_MAX;

        for (int i = 0; i < list1.size(); i++) {
            m[list1[i]] = i;
        }

        for (int i = 0; i < list2.size(); i++) {
            if (m.count(list2[i]) != 0) {
                if (m[list2[i]] + i < min) {
                    min = m[list2[i]] + i;
                    res.clear();
                    res.push_back(list2[i]);
                } else if (m[list2[i]] + i == min) {
                    res.push_back(list2[i]);
                }
            }
        }

        return res;
    }
};
