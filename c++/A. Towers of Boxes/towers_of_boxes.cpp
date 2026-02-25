#include<bits/stdc++.h>

using namespace std;


int main() {
  int t;
  cin >> t;

  int n, m, d;
  while(t--) {
    cin >> n >> m >> d;
    cout << n/(d/m + 1) + (n % (d/m + 1) != 0) << endl;
  }

  return 0;
}