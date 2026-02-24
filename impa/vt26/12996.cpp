#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;
    int case_counter {1};
    while (test_cases--)
    {
        int mangoes, limit;
        cin >> mangoes >> limit;
        vector<int> types(mangoes, 0);
        vector<int> specific_limit(mangoes, 0);
        bool cant {false};
        for (int i = 0; i < mangoes; i++) {
            cin >> types[i];
        }

        for (int i = 0; i < mangoes; i++) {
            cin >> specific_limit[i];
        }

        int total {};
        for (int i = 0; i < types.size(); i++) {
            total += types[i];
            if (types[i] > limit || types[i] > specific_limit[i]) {
                cant = true;
                break;
            }
        }

        if (cant || total > limit) {
            cout << "Case " << case_counter << ": No" << '\n';
        }
        else {
            cout << "Case " << case_counter << ": Yes" << '\n'; 
        }

        case_counter++;

    }

    return 0;
}