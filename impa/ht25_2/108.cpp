#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& v)
{
    int result {v[0]};
    int maxEnding {v[0]};

    for (int i = 1; i < v.size(); i++)
    {
        maxEnding = max(v[i], maxEnding + v[i]);
        result = max(result, maxEnding);
    }
    return result;
}

int main()
{
    int N;
    cin >> N;
    int maxSubRectangle {0};
    int tmp {0};

    vector<vector<int>> v(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> v[i][j];
        }
    }

    for (int row = 0; row < N; row++)
    {
        vector<int> sum(N, 0);
        for (int column = row; column < N; column++)
        {
            for(int i = 0; i < N; i++)
            {
                sum[i] += v[column][i];
            }
            tmp = maxSubArray(sum);
            if (tmp > maxSubRectangle)
                maxSubRectangle = tmp;
        }
    }

    cout << maxSubRectangle << endl;
    

    return 0;
}