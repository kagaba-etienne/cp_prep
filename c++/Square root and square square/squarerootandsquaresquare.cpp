#include <bits/stdc++.h>

using namespace std;

double C;

bool test_overflow(double x) {
  if (x*x + sqrt(x) > C) {
    return true;
  }

  return false;
}

int main() {
  cin >> C;

  double low = 1;
  double high = C;
  double mid;

  while(high-low > 1e-7) {
    mid = (high + low)/2;

    if (test_overflow(mid)) {
      high = mid;
    } else {
      low = mid;
    }
  }

  cout << fixed << setprecision(7)<< high << endl;
}