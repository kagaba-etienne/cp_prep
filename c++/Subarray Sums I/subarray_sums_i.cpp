#include<bits/stdc++.h>

using namespace std;


int main() {
  long long x,n;
  cin >>  n >> x;
  vector<long long> vec(n);
  for(long i = 0; i < n; i++) {
    cin >> vec[i];
  }

  long long ptr1, ptr2;
  long long sum = vec[0];
  long long subs = 0;

  ptr1 = ptr2 = 0;

  while(ptr1 < n) {
    if(sum  < x ) {
      if (ptr2 < n-1) {
        sum += vec[ptr2 + 1];
      } else {
        break;
      }
      ptr2 = min(ptr2 +1, n-1);
    } else if (sum > x) {
      sum -= vec[ptr1];
      ptr1++;
    } else {
      if (ptr2 < n-1) {
        sum += vec[ptr2 + 1];
      }
      sum -= vec[ptr1];
      ptr2 = min(ptr2 +1, n-1);
      ptr1++;
      subs++;
    }
  }

  cout <<  subs << endl;

  return 0;
}