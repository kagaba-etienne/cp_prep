#include<bits/stdc++.h>

using namespace std;

set<long long> factorize(long long n) {
    set<long long> factors;

    if (n % 2 == 0) {
        factors.insert(2);
        while (n % 2 == 0) n /= 2;
    }

    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            factors.insert(i);
            while (n % i == 0) n /= i;
        }
    }

    if (n > 1) {
        factors.insert(n);
    }

    return factors;
}

int main() {
  int t;
  cin >> t;

  long long n;

  while(t--) {
    cin >> n;

    set<long long> pfactors = factorize(n);

    long long product = 1;

    for(auto i : pfactors) {
      product *= i;
    }

    cout << product << endl;
  }
  return 0;
}