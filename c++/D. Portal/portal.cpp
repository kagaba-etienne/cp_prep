#include<bits/stdc++.h>

using namespace std;
#define vec vector

vec<long> least_rotation(vec<long>& arr) {
  int ptr1 = 0;
  int ptr2 = 1;
  int offset = 0;
  int n = arr.size();

  if(arr.size() < 2) {
    return arr;
  }

  vec<long> circular(arr.begin(), arr.end());
  circular.insert(circular.end(), arr.begin(), arr.end());

  while(ptr1 < n && ptr2 < n && offset < n) {
    auto a = circular[ptr1 + offset];
    auto b = circular[ptr2 + offset];

    if (a ==  b) {
      offset += 1;
    } else {
      if (a >  b) {
        ptr1 += offset + 1;
      } else {
        ptr2 += offset + 1;
      }

      if (ptr1 == ptr2) {
        ptr2 += 1;
      }

      offset = 0;
    }
  }

  int start = min(ptr1, ptr2);

  return vec(circular.begin() + start, circular.begin() + start + n);
}

int main() {
  int t;
  long x, y, n;

  cin >> t;

  while(t--) {
    cin >> n >> x >> y;
    vec<long> arr(n);

    for(int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    vec<long> mid(arr.begin() + x, arr.begin() + y);
    vec<long> rest;
    
    if (x != 0) {
      rest.insert(rest.end(), arr.begin(), arr.begin() + x);
    }
    
    rest.insert(rest.end(), arr.begin() +  y, arr.end());
    mid = least_rotation(mid);

    bool printed = false;

    for(auto i : rest) {
      if(!printed && i > mid[0]) {
        for(auto j : mid) {
          cout << j << " ";
        }
        printed = true;
      }

      cout << i <<  " ";
    }

    if(!printed) {
      for(auto i: mid) {
        cout << i << " ";
      }
    }
    cout << endl;
  }

  return 0;
}