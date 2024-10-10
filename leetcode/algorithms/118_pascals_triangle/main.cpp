#include <vector>
using namespace std;

class PascalsTriangle
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;

        for (int i = 0; i < numRows; i++)
        {
            vector<int> row;
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                {
                    row.push_back(1);
                }
                else
                {
                    row.push_back(result[i - 1][j - 1] + result[i - 1][j]);
                }
            }
            result.push_back(row);
        }

        return result;
    }

    // Best Solution 1: Using Recursion
    vector<vector<int>> bestSolution1(int numRows)
    {
        if (numRows == 0)
            return {};
        if (numRows == 1)
            return {{1}};

        vector<vector<int>> prevRows = bestSolution1(numRows - 1);
        vector<int> newRow(numRows, 1);

        for (int i = 1; i < numRows - 1; i++)
        {
            newRow[i] = prevRows.back()[i - 1] + prevRows.back()[i];
        }

        prevRows.push_back(newRow);
        return prevRows;
    }

    // Best Solution 2: Using Combinatorial Formula
    vector<vector<int>> bestSolution2(int numRows)
    {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++)
        {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                row[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            result.push_back(row);
        }
        return result;
    }

    // Best Solution 3: Using Dynamic Programming with 1D Array
    vector<vector<int>> bestSolution3(int numRows)
    {
        vector<vector<int>> result;
        vector<int> prevRow;

        for (int i = 0; i < numRows; i++)
        {
            vector<int> currentRow(i + 1, 1);

            for (int j = 1; j < i; j++)
            {
                currentRow[j] = prevRow[j - 1] + prevRow[j];
            }

            result.push_back(currentRow);
            prevRow = currentRow;
        }

        return result;
    }
};