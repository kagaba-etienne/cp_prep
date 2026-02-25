#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  string r;

  while(t--) {
    cin >> r;
    char last_letter = 'u';
    int count_ops = 0;

    for(int i = 0; i<r.size(); i++) {
      // handle the last element specially
      if (i == r.size() -1 && r[r.size()-1] == 'u') {
        count_ops++;
        break;
      }

      if (r[i] == last_letter && last_letter == 'u') {
        count_ops++;
        last_letter = 's';
        continue;
      }
      last_letter = r[i];
    }

    cout << count_ops << endl;
  }
}