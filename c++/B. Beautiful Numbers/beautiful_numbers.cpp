#include<bits/stdc++.h>

using namespace std;


int main() {
  int t;
  cin >> t;

  long long x;

  while(t--) {
    cin >> x;
    string chars = to_string(x);
    vector<int> digits(chars.size());

    if (chars.size() == 1) {
      cout << 0 << endl;
      continue;
    }
    
    for(int i = 0; i < chars.size(); i++) {
      digits[i] = chars[i] - '0';
    }
    swap(digits.front(), digits.back());
    auto first_num = digits.back();
    digits.pop_back();
    
    sort(digits.begin(), digits.end());
    digits.push_back(first_num);

    int sum1 = first_num;
    int swaps_no1 = 0;
    for(int j = 0; j < digits.size()-1; j++) {
      sum1 += digits[j];
      if (sum1 > 9) {
        swaps_no1 = digits.size() - (j + 1);
        break;
      }
    }

    int swaps_no2 = 1;
    int sum2 = 1;
    for(int k = 0; k < digits.size()-1; k++) {
      sum2 += digits[k];
      if (sum2 > 9) {
        swaps_no2 = digits.size() - k;
        break;
      }
    }
    cout << min(swaps_no1, swaps_no2) << endl;
  }

  return 0;
}