#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int C;
    cin >> C;

    for (int i = 0; i < C; i++)
    {
        double N;
        double total = 0;
        vector<int> grades;

        cin >> N;
        for (int j = 0; j < N; j++)
        {
            int grade;
            cin >> grade;
            total += grade;
            grades.push_back(grade);
        }
        double avg = total / N;

        double above = 0;
        for (int s = 0; s < N; s++)
        {
            if (grades[s] > avg)
                above++;
        }

        cout << fixed << setprecision(3) << (above / N) * 100 << "%" << endl;
    }


    return 0;
}