#include<bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;

  int n;
  while(t--) {
    cin >> n;
    vector<int> nums(n);
    int largest = 0;
    int largest_idx = 0;

    for(int i = 0; i < n; i++) {
      cin >> nums[i];
      if (nums[i] > largest) {
          largest = nums[i];
          largest_idx = i;
      }
    }

    swap(nums[largest_idx], nums[0]);

    for(int j=0; j < n; j++) {
      cout << nums[j] << " ";
    }
    cout << endl;
  }
  return 0;
}