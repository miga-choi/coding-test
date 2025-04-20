#include <numeric>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class BaseballGame {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scoreArray;

        for (int i = 0; i < operations.size(); i++) {
            if (operations.at(i).front() == '+') {
                scoreArray.push_back(accumulate(scoreArray.end() - 2, scoreArray.end(), 0));
            } else if (operations.at(i).front() == 'D') {
                scoreArray.push_back(scoreArray.back() * 2);
            } else if (operations.at(i).front() == 'C') {
                scoreArray.pop_back();
            } else {
                scoreArray.push_back(stoi(operations.at(i)));
            }
        }

        return accumulate(scoreArray.begin(), scoreArray.end(), 0);
    }


    // Solution
    int calPoints(vector<string>& ops) {
        int value1;
        int value2;
        int ans = 0;
        stack<int> stk;

        for (string i : ops) {
            if (i == "C") {
                stk.pop();
            } else if (i == "D") {
                stk.push(stk.top() * 2);
            } else if (i == "+") {
                value1 = stk.top();
                stk.pop();
                value2 = stk.top();
                stk.push(value1);
                stk.push(value1 + value2);
            } else {
                // stoi() to convert string into integer
                stk.push(stoi(i));
            }
        }
        
        while (stk.size() != 0) {
            ans += stk.top();
            stk.pop();
        }

        return ans;
    }
};
