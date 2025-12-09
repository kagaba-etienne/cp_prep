#include <bits/stdc++.h>
using namespace std;

#define REP(i,x,y) for(int i=(x); i<(y); i++)
#define PRINT(y) for(auto x: (y)) cout<<x<<" "

// Tried this but it was slow and getting TLE on some test cases (because of large number of duplicates [degrades to O(n^2)], sorted arrays)
vector<int>::iterator  partition_lomuto(vector<int>::iterator p, vector<int>::iterator r) {
  vector<int>::iterator i = p-1;
  vector<int>::iterator x = r-1;

  for(vector<int>::iterator j = p; j != r-1; j++) {
    if(*j <= *x) {
      ++i;
      int temp = *i;
      *i = *j;
      *j = temp;
    }
  }

  auto pivot = i+1;
  int temp = *pivot;

  *pivot = *x;
  *x = temp;

  return pivot;
}

// Fast enough to pass the test cases (due to random pivot and hoare partitioning)
vector<int>::iterator  partition_hoare(vector<int>::iterator p, vector<int>::iterator r) {
  int n = r - p;
  iter_swap(p, p + (rand() % n));

  int x = *p;
  vector<int>::iterator i = p - 1;
  vector<int>::iterator j = r;

  while(true) {
    do {
      j--;
    } while (*j > x);

    do {
      i++;
    } while (*i < x);

    if(i >= j) {
      return j;
    }

    iter_swap(i, j);
  }
}

void quicksort_hoare(vector<int>::iterator begin, vector<int>::iterator end) {
  if (distance(begin, end) < 2) {
    return;
  }
  auto pivot = partition_hoare(begin, end);
  quicksort(begin, pivot+1);
  quicksort(pivot+1, end);
}

void quicksort_lomuto(vector<int>::iterator begin, vector<int>::iterator end) {
  if (distance(begin, end) < 2) {
    return;
  }
  auto pivot = partition_lomuto(begin, end);
  quicksort(begin, pivot);
  quicksort(pivot+1, end);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  srand(time(NULL));
  
  int n;
  cin >> n;
  vector<int> arr(n);

  REP(i, 0, n) cin>>arr[i];
  
  quicksort(arr.begin(), arr.end());

  PRINT(arr);

  return 0;
}
