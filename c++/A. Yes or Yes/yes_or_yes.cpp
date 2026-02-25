#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  string s;

  while(t--) {
    cin >> s;

    int yes_count = 0;
    for(int i=0; i<s.size(); i++) {
      if(s[i] == 'Y') {
        yes_count++;
      }

      if (yes_count >= 2) {
        cout << "NO"<<endl;
        break;
      }
    }

    if (yes_count < 2) {
      cout << "YES" << endl;
    }
  }
}