#include<bits/stdc++.h>

using namespace std;
#define vec vector
#define ll long long


vec<ll> filter(const unordered_set<ll>& s, const vec<ll>& arr) {
  vec<ll> new_arr;
  for(auto i: arr) {
    if (s.find(i) == s.end()) {
      new_arr.push_back(i);
    }
  }
  return new_arr;
}


int main() {
  int t;
  cin >> t;

  int n;
  
  while(t--) {
    cin >> n;

    vec<vec<ll>> blogs(n);
    int user_mentions;
    for(int i = 0; i < n; i++) {
      cin >> user_mentions;
      unordered_set<ll> added_users;
      vec<ll> temp;
      ll user_id;
      for(int j = 0; j < user_mentions; j++) {
        cin >> user_id;
        temp.push_back(user_id);
      }
      reverse(temp.begin(), temp.end());
      for(int m = 0; m < user_mentions; m++) {
        if((added_users.insert(temp[m])).second) {
          blogs[i].push_back(temp[m]);
        }
      }
    }

    sort(blogs.begin(), blogs.end());

    vec<ll> Q;
    unordered_set<ll> unique_q;

    for(int k = 0; k < n; k++) {
      if(blogs[k].empty()) {
        continue;
      }
      for(int l = 0; l < blogs[k].size(); l++) {
        if(unique_q.insert(blogs[k][l]).second) {
          Q.push_back(blogs[k][l]);
        }
      }

      for(int a = k+1; a < n; a++) {
        blogs[a] = filter(unique_q, blogs[a]);
      }

      sort(blogs.begin() + k + 1, blogs.end());
    }

    for(auto d: Q) {
      cout << d << " ";
    }
    cout << endl;
  }
  return 0;
}