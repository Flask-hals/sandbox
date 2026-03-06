#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set<string> words;
    string line;
    string current {""};

    while(getline(cin, line)) {
        bool hyphenated = false;
        if (!line.empty() && line.back() == '-') {
            hyphenated = true;
            line.pop_back();
        }

        for (char c : line) {
            if (isalpha(c)) {
                current += tolower(c);
            }
            else if (c == '-') {
                current += '-';
            }
            else {
                if (!current.empty()) {
                    words.insert(current);
                    current = "";
                }
            }
        }
        if (!hyphenated) {
            if (!current.empty()) {
                words.insert(current);
                current = "";
            }
        }
    }

    if (!current.empty()) {
        words.insert(current);
    }

    for (const string& w : words) {
        cout << w << '\n';
    }

    return 0;
}