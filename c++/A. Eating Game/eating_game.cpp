#include<bits/stdc++.h>

using namespace std;
#define vec vector

int play(vec<int>& arr, int& sum) {
  unordered_set<int> winners;

  for(int i = 0; i < arr.size(); i++) {
    vec<int> arr1 = arr;
    int session = sum;
    int current = i;
    while(session > 1) {
      if (arr1[current] > 0) {
        arr1[current]--;
        session--;
      }

      current = (current + 1) % arr.size();
    }
    
    for(int j = 0; j < arr.size(); j++) {
      if(arr1[j] > 0) {
        winners.insert(j);
        break;
      }
    }
  }

  return winners.size();
}

int main() {
  int t, n;
  cin >> t;

  while(t--) {
    cin >> n;
    vec<int> arr(n);
    int sum = 0;

    for(int i = 0; i < n; i++) {
      cin >> arr[i];
      sum += arr[i];
    }

    cout << play(arr, sum)<<endl;
  }

  return 0;
}