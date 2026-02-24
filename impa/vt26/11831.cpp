#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int rows, columns, instructions;

    while (cin >> rows >> columns >> instructions && (rows != 0 || columns != 0 || instructions != 0)) {


        vector<vector<char>> vv (rows, vector<char>(columns, '*'));

        int posx {};
        int posy {};

        int stickers_collected {};

        cin.ignore();

        for (int y = 0; y < rows; y++) {
            string line;
            getline(cin, line);
            for (int x = 0; x < columns; x++) {
                vv[y][x] = line[x];
                if (line[x] == 'N' || line[x] == 'S' || line[x] == 'L' || line[x] == 'O') {
                    posx = x;
                    posy = y;
                }
            }
        }

        for (int i = 0; i < instructions; i++) {
            char c;
            cin >> c;
            if (c == 'D') {
                if (vv[posy][posx] == 'N') {
                    vv[posy][posx] = 'L';
                }
                else if (vv[posy][posx] == 'L') {
                    vv[posy][posx] = 'S';
                }
                else if (vv[posy][posx] == 'S') {
                    vv[posy][posx] = 'O';
                }
                else if (vv[posy][posx] == 'O') {
                    vv[posy][posx] = 'N';
                }
            }
            else if (c == 'E') {
                if (vv[posy][posx] == 'N') {
                    vv[posy][posx] = 'O';
                }
                else if (vv[posy][posx] == 'O') {
                    vv[posy][posx] = 'S';
                }
                else if (vv[posy][posx] == 'S') {
                    vv[posy][posx] = 'L';
                }
                else if (vv[posy][posx] == 'L') {
                    vv[posy][posx] = 'N';
                }
            }
            else {
                if (vv[posy][posx] == 'N') {
                    if (posy == 0 || vv[posy - 1][posx] == '#') {
                        continue;
                    }
                    else {
                        if (vv[posy - 1][posx] == '*') {
                            stickers_collected++;
                        }
                        vv[posy][posx] = '.';
                        posy--;
                        vv[posy][posx] = 'N';
                    }
                }
                else if (vv[posy][posx] == 'S') {
                    if (posy == rows - 1 || vv[posy + 1][posx] == '#') {
                        continue;
                    }
                    else {
                        if (vv[posy + 1][posx] == '*') {
                            stickers_collected++;
                        }
                        vv[posy][posx] = '.';
                        posy++;
                        vv[posy][posx] = 'S';
                    }
                }
                else if (vv[posy][posx] == 'L') {
                    if (posx == columns - 1 || vv[posy][posx + 1] == '#') {
                        continue;
                    }
                    else {
                        if (vv[posy][posx+1] == '*') {
                            stickers_collected++;
                        }
                        vv[posy][posx] = '.';
                        posx++;
                        vv[posy][posx] = 'L'; 
                    }
                }
                else if (vv[posy][posx] == 'O') {
                    if (posx == 0 || vv[posy][posx - 1] == '#') {
                        continue;
                    }
                    else {
                        if (vv[posy][posx - 1] == '*') {
                            stickers_collected++;
                        }
                        vv[posy][posx] = '.';
                        posx--;
                        vv[posy][posx] = 'O';
                    }
                }
            }
        }

        cout << stickers_collected << '\n';
    }

    return 0;
}