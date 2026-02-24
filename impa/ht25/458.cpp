#include <iostream>

using namespace std;

int main()
{
    string line;
    while(cin >> line)
    {
        string decoded {""};
        for(char c : line)
        {
            decoded += (char)(c - 7);
        }
        cout << decoded << endl;
    }

    return 0;
}