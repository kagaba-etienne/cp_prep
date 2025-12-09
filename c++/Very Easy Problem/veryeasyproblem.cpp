#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
int x,y;

bool can_print_in(ll sec) {
  ll fast_printer = sec/min(x,y);
  ll slow_printer = (sec-min(x,y))/max(x,y);

  if (fast_printer + slow_printer >= n) {
    return true;
  }

  return false;
}

int main() {
  cin >> n >> x >> y;

  ll low = min(x, y);
  ll high = n*min(x,y);
  ll mid;
  ll ans;

  while(low <= high) {
    mid = (low + high)/2;
    
    if(can_print_in(mid)) {
      ans = mid;
      high = mid-1;
    } else {
      low = mid+1;
    }
  }

  cout << ans;

  return 0;
}