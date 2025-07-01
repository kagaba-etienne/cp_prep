#include <iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

int main() {
    int t,n;
    cin>>t;
    while(t--) {
        cin>>n;
        set<int> nums_right;
        set<int> nums_left;
        vector<int> nums_vec(n);
        
        for(int i=0; i<n; i++) {
            int temp;
            cin>>temp;
            nums_right.insert(temp);
            nums_vec[i] = temp;
        }
        
        for(int j=0; j<n; j++) {
            auto it = nums_right.find(nums_vec[j]);
            int current = *it;
            nums_right.erase(it);
            
            bool greater = false;
            bool less = false;
            
            auto it1 = nums_right.upper_bound(current);
            if(it1 != nums_right.end()) greater = true;
            
            if(!nums_left.empty() && *nums_left.begin() < current) less = true;
            
            if(greater && less) {
                cout<<"0";
            } else {
                cout<<"1";
            }
            nums_left.insert(current);
        }
        cout<<endl;
    }
    return 0;
}