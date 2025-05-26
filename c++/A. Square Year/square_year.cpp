#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    t=1;
    while(t--) {
        int s;
        cin>>s;
        int i = -1;
        
        while(i<=sqrt((double)s)) {
            i++;
            if((i*i) == s) break;
        }

        if ((i*i) ==s) {
            cout<<i<<" "<< 0;
        } else {
            cout<<-1;
        }

        cout<<endl;
    }
    return 0;
}