#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
 
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        
        vector<long long> b(n);
        
        for(int i=0; i<n; i++) {
            cin>>b[i];
        }
        
        long long prev;
        for(int i=0; i<n-1; i++) {
            prev = gcd(b[i], b[i+1]);
            b[i] = b[i]/prev;
        }
        
        long long answer = 1;
        for(int i=0; i<n-1; i++) {
            if(b[i] != 1 && answer == 1) {
                answer = b[i];
                continue;
            }
            
            if(b[i] != 1) {
                answer = lcm(answer, b[i]);
            }
        }
        
        cout<<answer<<endl;
    }
    return 0;
}