#include <iostream>
#include <string>
#include <bit>
#include <bitset>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin>>t;

    while(t--) {
        ll n, k;
        cin>>n>>k;
        
        string s;
        cin>>s;

        ll ones = 0;
        for (char c : s) {
            if (c == '1') ones++;
        }

        ll zeros = n - ones;

        ll max_pairs = ones/2 + zeros/2;

        if(max_pairs == k) {
            cout<<"YES"<<endl;
            continue;
        }
        if (max_pairs < k) {
            cout<<"NO"<<endl;
            continue;
        }

        ll rest = max_pairs - min(ones/2, zeros/2)*2;
        ll matched = max_pairs - rest;

        if(rest == k) {
            cout<<"YES"<<endl;
            continue;
        }

        if(rest > k) {
            cout<< "NO"<<endl;
            continue;
        }

        if(matched/2 >= (k-rest)/2 && !((k-rest) % 2)) {
            cout<<"YES"<<endl;
            continue;
        } else {
            cout<< "NO"<<endl;
            continue;
        }
    }

    return 0;
}