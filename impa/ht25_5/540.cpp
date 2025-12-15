#include <cstddef>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <set>
#include <limits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k {1};
    int t;
    while (cin >> t && t != 0)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        unordered_map<int, int> teams; // fel här
        for (size_t i = 0; i < t; i++)
        {
            string team;
            getline(cin, team);
            stringstream ss {team};
            int element;
            ss >> element;
            while (ss >> element)
            {
                teams[element] = i;
            }
        }

        vector<queue<int>> teamQueues (t);
        queue<int> globalQueue;
        set<int> teamsInGlobalQueue;
        cout << "Scenario #" << k << "\n";
        string line;
        while (getline(cin, line) && line != "STOP")
        {
            stringstream ss {line};
            string command;
            ss >> command;
            if (command == "ENQUEUE")
            {
                int elementToEnque;
                ss >> elementToEnque;
                teamQueues[teams[elementToEnque]].push(elementToEnque);
                if (teamsInGlobalQueue.find(teams[elementToEnque]) == teamsInGlobalQueue.end())
                {
                    teamsInGlobalQueue.insert(teams[elementToEnque]);
                    globalQueue.push(teams[elementToEnque]);
                }
            }
            else
            {
                int teamToDequeue = globalQueue.front();
                cout << "dequeueing from team: " << teamToDequeue << " element: " << teamQueues[teamToDequeue].front() << endl;
                cout << teamQueues[teamToDequeue].front() << "\n"; teamQueues[teamToDequeue].pop();
                if (teamQueues[teamToDequeue].empty())
                {
                    globalQueue.pop();
                    teamsInGlobalQueue.erase(teamToDequeue);
                }
            }
        }
        k++;
        cout << "\n";
    }
    cout << flush;
    return 0;
}
/*
8
10 0 1 2 3 4 5 6 7 8 9
2 10 11
2 20 21
2 30 31
9 40 41 42 43 44 45 46 47 48
10 50 51 52 53 54 55 56 57 58 59
5 60 61 62 63 64
5 70 71 72 73 74
ENQUEUE 63
DEQUEUE
ENQUEUE 11
DEQUEUE
ENQUEUE 55
ENQUEUE 53
DEQUEUE
ENQUEUE 72
DEQUEUE
ENQUEUE 42
ENQUEUE 45
DEQUEUE
ENQUEUE 1
ENQUEUE 6
DEQUEUE
DEQUEUE
DEQUEUE
ENQUEUE 10
ENQUEUE 4
ENQUEUE 50
ENQUEUE 48
ENQUEUE 7
DEQUEUE
ENQUEUE 62
ENQUEUE 55
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
STOP
9
9 0 1 2 3 4 5 6 7 8
6 10 11 12 13 14 15
2 20 21
1 30
9 40 41 42 43 44 45 46 47 48
6 50 51 52 53 54 55
4 60 61 62 63
3 70 71 72
8 80 81 82 83 84 85 86 87
ENQUEUE 80
ENQUEUE 63
ENQUEUE 14
DEQUEUE
STOP
4
1 0
5 10 11 12 13 14
5 20 21 22 23 24
3 30 31 32
ENQUEUE 24
DEQUEUE
ENQUEUE 30
ENQUEUE 20
DEQUEUE
ENQUEUE 30
DEQUEUE
DEQUEUE
ENQUEUE 10
ENQUEUE 10
ENQUEUE 11
ENQUEUE 11
ENQUEUE 30
ENQUEUE 21
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
ENQUEUE 20
DEQUEUE
ENQUEUE 10
DEQUEUE
ENQUEUE 23
DEQUEUE
DEQUEUE
DEQUEUE
ENQUEUE 23
DEQUEUE
ENQUEUE 24
DEQUEUE
ENQUEUE 14
DEQUEUE
ENQUEUE 10
DEQUEUE
ENQUEUE 22
ENQUEUE 13
ENQUEUE 30
DEQUEUE
DEQUEUE
ENQUEUE 10
DEQUEUE
ENQUEUE 20
DEQUEUE
STOP
5
8 0 1 2 3 4 5 6 7
2 10 11
6 20 21 22 23 24 25
10 30 31 32 33 34 35 36 37 38 39
10 40 41 42 43 44 45 46 47 48 49
ENQUEUE 40
DEQUEUE
ENQUEUE 48
DEQUEUE
ENQUEUE 10
DEQUEUE
ENQUEUE 22
ENQUEUE 4
ENQUEUE 7
STOP
8
4 0 1 2 3
6 10 11 12 13 14 15
6 20 21 22 23 24 25
2 30 31
7 40 41 42 43 44 45 46
10 50 51 52 53 54 55 56 57 58 59
6 60 61 62 63 64 65
9 70 71 72 73 74 75 76 77 78
ENQUEUE 21
ENQUEUE 75
ENQUEUE 56
DEQUEUE
DEQUEUE
DEQUEUE
ENQUEUE 11
ENQUEUE 11
DEQUEUE
STOP
3
4 0 1 2 3
10 10 11 12 13 14 15 16 17 18 19
2 20 21
ENQUEUE 12
DEQUEUE
ENQUEUE 11
ENQUEUE 1
ENQUEUE 1
ENQUEUE 12
ENQUEUE 12
DEQUEUE
ENQUEUE 1
ENQUEUE 20
DEQUEUE
DEQUEUE
ENQUEUE 11
ENQUEUE 1
ENQUEUE 10
DEQUEUE
DEQUEUE
DEQUEUE
ENQUEUE 15
ENQUEUE 13
DEQUEUE
DEQUEUE
ENQUEUE 11
DEQUEUE
DEQUEUE
ENQUEUE 14
ENQUEUE 11
ENQUEUE 16
ENQUEUE 21
ENQUEUE 17
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
ENQUEUE 11
STOP
3
9 0 1 2 3 4 5 6 7 8
9 10 11 12 13 14 15 16 17 18
1 20
ENQUEUE 8
DEQUEUE
ENQUEUE 2
ENQUEUE 7
DEQUEUE
ENQUEUE 17
ENQUEUE 17
ENQUEUE 13
ENQUEUE 12
DEQUEUE
ENQUEUE 8
DEQUEUE
ENQUEUE 1
ENQUEUE 5
DEQUEUE
ENQUEUE 3
DEQUEUE
DEQUEUE
DEQUEUE
ENQUEUE 7
DEQUEUE
DEQUEUE
ENQUEUE 0
ENQUEUE 2
ENQUEUE 7
ENQUEUE 17
ENQUEUE 15
ENQUEUE 14
ENQUEUE 4
ENQUEUE 13
DEQUEUE
ENQUEUE 14
ENQUEUE 13
ENQUEUE 8
ENQUEUE 4
ENQUEUE 3
DEQUEUE
DEQUEUE
ENQUEUE 2
DEQUEUE
ENQUEUE 13
ENQUEUE 0
DEQUEUE
DEQUEUE
ENQUEUE 16
ENQUEUE 7
DEQUEUE
ENQUEUE 12
ENQUEUE 7
ENQUEUE 7
ENQUEUE 8
DEQUEUE
DEQUEUE
ENQUEUE 14
ENQUEUE 20
DEQUEUE
DEQUEUE
ENQUEUE 18
STOP

Scenario #1
63
11
55
53
72
42
45
1
6
4
7
10
50

Scenario #2
80

Scenario #3
24
30
20
30
10
10
11
11
30
21
20
23
10
23
24
14
10
22
13
30
10

Scenario #4
40
48
10

Scenario #5
21
75
56
11

Scenario #6
12
11
12
12
1
1
1
1
20
11
10
15
13
11
14
11
16

Scenario #7
8
2
7
17
17
13
12
8
5
3
7
0
2
7
4
8
4
3
2
0
7


*/