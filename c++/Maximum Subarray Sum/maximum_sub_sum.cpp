#include<bits/stdc++.h>

using namespace std;


int main() {
  long long n;
  cin >> n;

  vector<long long> vec(n);

  for(long long i = 0; i < n ; i++) {
    cin >> vec[i];
  }

  long long lo, hi, sum;
  lo = 0;
  hi = numeric_limits<long long>::min();
  sum = 0;

  for(long long i = 0; i < n; i++) {
    sum += vec[i];
    hi = max(hi, sum - lo);
    lo = min(lo, sum);
  }


  cout << hi << endl;

  return 0;
}