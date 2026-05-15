#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string in;
    set<string> s;
    int counter {1};

    while (cin >> in) {
        if (in == "9") {
            bool not_decodable {false};
            set<string>::iterator itr;
            for (itr = s.begin(); itr != s.end(); itr++) {
                for (int i = 1; i < (*itr).length(); i++) {
                    string sub = (*itr).substr(0, i);
                    if (s.count(sub) == 1) {
                        cout << "Set " << counter << " is not immediately decodable" << '\n';
                        not_decodable = true;
                        break;
                    }
                }
                if (not_decodable) {
                    break;
                }
            }
            if (!not_decodable) {
                cout << "Set " << counter << " is immediately decodable" << '\n';
            }
            counter++;
            s.clear();
            continue;
        }
        s.insert(in);
    }

    return 0;
}