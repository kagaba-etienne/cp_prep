#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        
        vector<int> a(n);
        
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }
        
        int minimum = a[0];
        if(a[0] < a[1]) {
            cout<<minimum*2<<endl;
        } else {
            cout<<minimum+a[1]<<endl;
        }
    }
    return 0;
}