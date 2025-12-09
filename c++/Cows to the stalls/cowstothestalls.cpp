#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N,K;
vector<ll> coords;

bool can_place(ll distance) {
  ll placed = 1;
  ll last_coord = coords[0];

  for (ll i = 1; i<coords.size(); i++) {
    if(coords[i] - last_coord >= distance) {
      placed++;
      last_coord = coords[i];
    }

    if (placed >= K) {
      return true;
    }
  }

  return false;
}

int main() {
  cin >> N >> K;
  for(ll i =0; i<N; i++) {
    ll curr;
    cin >> curr;
    coords.push_back(curr);
  }

  ll low = 1;
  ll high = coords[N-1] - coords[0];
  ll ans;

  while(low <= high) {
    ll mid = (high+low)/2;

    if(can_place(mid)) {
      ans = mid;
      low = mid+1;
    } else {
      high = mid-1;
    }
  }

  cout << ans;
  return 0;
}