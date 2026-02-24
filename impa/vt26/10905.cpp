#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    while (cin >> n && n != 0) {
        vector<string> v;

        cin.ignore();

        string line;
        getline(cin, line);

        stringstream ss {line};

        string tmp;

        while (ss >> tmp) {
            v.push_back(tmp);
        }

        std::sort(v.begin(), v.end(), [](string& a, string& b) {
            return a + b > b + a;
        });

        for (string i : v) {
            cout << i;
        }
        cout << "\n";

    }
}