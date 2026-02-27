#include<bits/stdc++.h>

using namespace std;
#define vec vector

int main() {
  int t, n;

  cin >> t;

  while(t--) {
    cin >> n;
    vec<int> arr(n);
    int idx = 0;
    bool decreasing = false;

    for(int i = 0; i < n; i++) {
      cin >> arr[i];
      if (i > 0 && arr[i] < arr[i-1]) {
        decreasing = true;
        idx = i;
      }
    }

    if (decreasing) {
      cout << 1 << endl;
    } else {
      cout << n << endl;
    }
  }

  return 0;
}