#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

bool isSafe(const vector<vector<int>>& mat, int row, int col)
{
    for (int i = 0; i < row; i++)
        if (mat[i][col]) return false;

    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if (mat[i][j]) return false;

    for (int i = row-1, j = col+1; i >= 0 && j < 8; i--, j++)
        if (mat[i][j]) return false;

    return true;
}

int placeQueens(vector<vector<int>>& mat, const vector<vector<int>>& v, int row)
{
    int bestSum = numeric_limits<int>::min();
    if (row == 8)
    {
        return 0;
    }

    for(int i = 0; i < 8; i++)
    {
        if(isSafe(mat, row, i))
        {
            mat[row][i] = 1;
            int currSum = v[row][i] + placeQueens(mat, v, row + 1);
            bestSum = max(bestSum, currSum);
            mat[row][i] = 0;
        }
    }
    return bestSum;
}

int main()
{
    int k;
    cin >> k;
    while(k--)
    {
        vector<vector<int>> v(8, vector<int>(8));
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                int num;
                cin >> num;
                v[i][j] = num;
            }
        }
        vector<vector<int>> mat(8, vector<int>(8, 0));
        cout << setw(5) << placeQueens(mat, v, 0) << endl;
    }

    return 0;
}