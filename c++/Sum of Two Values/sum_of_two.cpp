#include<bits/stdc++.h>

using namespace std;

int main() {
  long long n, x;
  cin >> n >> x;

  vector<long long> vec(n);

  map<long long, long long> nums;
  multimap<long long, long long> pos;

  for (int i = 0; i < n; i++) {
    cin >> vec[i];
    pos.insert({vec[i], i});
    if(nums.find(vec[i]) != nums.end()) {
      nums[vec[i]] += 1;
    } else {
      nums.insert({vec[i], 1});
    }
  }

  for(int i = 0; i < n;  i++) {
    long long y = x - vec[i];

    auto it = nums.find(y);
    if(it != nums.end()) {
      if(y == vec[i] && it->second < 2) continue;
      if(y == vec[i] && it->second > 1) {
        auto range = pos.equal_range(y);
        auto it1 = range.first;
        cout << it1->second + 1 << " " << next(it1)->second + 1;
        return 0;
      }
      
      auto it2 = pos.find(y);
      cout << i + 1 << " " << it2->second + 1 << endl;
      return 0;
    }
  }

  cout << "IMPOSSIBLE" << endl;

  return 0;
}