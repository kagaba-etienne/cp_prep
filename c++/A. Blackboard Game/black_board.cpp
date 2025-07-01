#include <iostream>
using namespace std;
 
int main() {
    int t,n;
    cin>>t;
    while(t--) {
        cin>>n;
        if((n-1)%4 == 3) {
            cout<<"Bob"<<endl;
        } else {
            cout<<"Alice"<<endl;
        }
    }
    return 0;
}