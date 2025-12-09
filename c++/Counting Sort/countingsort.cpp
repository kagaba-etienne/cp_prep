#include <bits/stdc++.h>

using namespace std;

#define REP(i,x,y) for(int i=(x); i<(y); i++)

#define PRINT(y) for(auto x: (y)) cout<<x<<" "

const int RANGE_SIZE = 20001;
const int OFFSET = 10000;

void counting_sort(vector<int>& A, vector<int>& B) {
  vector<int> C(RANGE_SIZE,0);

  REP(j, 0, A.size()) C[A[j] + OFFSET] += 1;

  REP(i, 1, RANGE_SIZE) C[i] = C[i-1] + C[i];

  for(int j=A.size()-1; j >= 0; j--) {
    B[C[A[j] + OFFSET]-1] = A[j];
    C[A[j] + OFFSET] -= 1;
  }

  return;
}

int main() {
  int n, largest;
  cin>> n;

  vector<int> a(n), b(n);

  REP(i,0,n) {
    cin >> a[i];
  }
  counting_sort(a, b);
  PRINT(b);

  return 0;
}