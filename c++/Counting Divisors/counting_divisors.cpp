#include<bits/stdc++.h>

using namespace std;

long first_factor(long n) {
  if (n == 1) return 1;
  
  if(n % 2 == 0) {
    return 2;
  }

  int i = 3;
  while(i*i <= n) {
     if(n % i == 0) {
      return i;
     }
     i += 2;
  }

  return n;
}

map<long, long> factorize(long n) {
  map<long, long> factors;

  while(n > 1) {
    long factor = first_factor(n);
    factors.insert({factor, 0});
    while(n % factor == 0) {
      n /= factor;
      factors[factor]++;
    }
  }

  return factors;
}

int main() {
  long n;
  cin >> n;

  while(n--) {
    long x;
    cin >> x;

    map<long, long> factors = factorize(x);
    long product = 1;
    for(auto factor: factors) {
      product *= factor.second + 1;
    }

    cout << product << endl;
  }
  return 0;
}