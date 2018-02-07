/*
//
// Created by héctor garcía costa on 7/2/18.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, tmp, cases;
    string input;
    map<int, string> persons;
    int votes[1001][21];
    map<int, bool> deleted;
    // Get the number of cases
    cin >> cases;
    while (cases--) {
        // Get the number of persons
        cin >> n;
        cin.ignore(100, '\n');
        // Clear the lists
        persons.clear();
        deleted.clear();

        for (int i = 1; i <= n; i++) {
            // Get the first person
            getline(cin, input);
            persons[i] = input;
        }

        int cur = 0;
        // While we can read more and not is a break line
        while (cin.peek() != '\n' && cin.peek() != -1) {
            for (int i = 0; i < n; i++) {
                cin >> votes[cur][i];
            }
            cin.ignore(100, '\n');
            cur++;
        }
        int best;
        int count[21];

        while (true) {
            best = 0;
            fill(count, count + 21, 0);
            for (int i = 0; i < cur; i++) {
                for (int j = 0; j < n; j++) {
                    if (deleted[votes[i][j]]) {
                        continue;
                    }
                    count[votes[i][j]]++;
                    if (count[votes[i][j]] > best) {
                        best = count[votes[i][j]];
                    }
                    break;
                }
            }
            if (best * 2 > cur)
                break;

            int lowest = best;
            for (int i = 1; i <= n; i++) {
                if (deleted[i]) continue;

                if (count[i] < lowest)
                    lowest = count[i];
            }

            if (lowest == best)
                break;

            for (int i = 1; i <= n; i++) {
                if (deleted[i]) continue;
                if (count[i] == lowest)
                    deleted[i] = true;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (deleted[i]) continue;

            if (count[i] == best)
                cout << persons[i] << endl;
        }

        if (cases)
            cout << endl;
    }

    return 0;

}*/
