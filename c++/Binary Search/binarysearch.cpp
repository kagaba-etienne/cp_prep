#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<int> vec1, vec2;

bool bin(int x) {
  int low = 0;
  int high = n-1;
  int mid;

  while(low <= high) {
    mid = (low + high)/2;
    
    if (x == vec1[mid]) {
      return true;
    } else if (x > vec1[mid]) {
      low = mid+1;
    } else {
      high = mid-1;
    }
  }

  return false;
}


int main() {
  cin >>  n >> k;

  for(int i = 0; i<n; i++) {
    int num;
    cin >> num;
    vec1.push_back(num);
  }

  for(int i = 0; i<k; i++) {
    int num;
    cin >> num;
    vec2.push_back(num);
  }

  for(int i = 0; i<k; i++) {
    if(bin(vec2[i])) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}