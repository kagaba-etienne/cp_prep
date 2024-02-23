#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int l=0; l < t; l++) {
        int n, k;
        cin >> n;
        cin >> k;
        map<long long, long long> monsters;
        vector<long long> a(n);

        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }

        for (int i = 0; i < n; i++) {
            long long distance;
            cin >> distance;
            auto dup = monsters.find(abs(distance));

            if (dup != monsters.end()) {
                monsters[abs(distance)] += a[i];
            } else {
                monsters[abs(distance)] = a[i];
            }
        }

        long long rem = 0;
        long long last_secs = 0;
        bool possible = true;
        for (auto& monster : monsters) {
            long long shots = (monster.first - last_secs) * k + rem;
            if (monster.second <= shots) {
                rem = shots - monster.second;
            } else {
                possible = false;
                break;
            }
            last_secs = monster.first;
        }

        if (possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}