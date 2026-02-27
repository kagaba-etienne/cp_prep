#include<bits/stdc++.h>

using namespace std;
#define vec vector

int main() {
  int t, n;

  cin >> t;

  while(t--) {
    cin >> n;

    string s;
    cin >> s;
    stack<char> last;

    for(auto c: s) {
      if (last.empty()) {
        last.push(c);
        continue;
      }

      char top = last.top();

      if (top == c) {
        last.pop();
        continue;
      }

      last.push(c);
    }

    if(last.empty()) {
      cout << "YES";
    } else {
      cout << "NO";
    }

    cout << endl;
  }

  return 0;
}