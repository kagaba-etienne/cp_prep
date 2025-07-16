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
        
        vector<int> a(n, 0);
        vector<bool> removed(n, false);
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }
        
        vector<int> c;
        c = a;
        
        sort(c.begin(), c.end());
        int counter = 0;
        
        for(int j=0; j<n; j++) {
            if(!removed[j] && a[j] == c[j]) {
                removed[j] = true;
                counter += 1;
            }
        }
        
        if(counter == a.size()) {
            cout<<"NO"<<endl;
            continue;
        }
        
        cout<<"YES"<<endl<<a.size()-counter<<endl;
        for(int k=0; k<n; k++) {
            if(!removed[k]) {
                if(k==removed.size()-1) {
                    cout<<a[k]<<endl;
                    continue;
                }
                
                cout<<a[k]<<" ";
            }
        }
    }
    
}