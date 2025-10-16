#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    while(cin >> n && n != 0)
    {
        int m;
        cin >> m;
        vector<vector<int>> v(n, vector<int>(m));

        for(int i = 0; i < n; i++)
        {
            string row;
            cin >> row;
            int index {0};
            int last {0};
            for(char c : row)
            {
                int current = c - '0';
                if (current != 0)
                {
                    v[i][index] = last + current;
                    last += current;
                }
                else
                {
                    v[i][index] = current;
                    last = 0;
                }
                index++;
            }
        }
        int rectangles {0};
        for(int k = 0; k < n; k++)
        {
            for(int l = 0; l < m; l++)
            {
                if(k == 0)
                    rectangles += v[k][l];
                else
                {
                    rectangles += v[k][l];
                    if (v[k][l])
                    {
                        int min_width = v[k][l];
                        int row = k-1;
                        while(row >= 0 && v[row][l])
                        {
                            min_width = min(min_width, v[row][l]);
                            rectangles += min_width;
                            row--;
                        }
                    }
                }
            }
        }

        cout << rectangles << endl;
    }

    return 0;
}