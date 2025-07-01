// Online C++ compiler to run C++ program online
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int t,n,j,k;
    cin>>t;
    while(t--) {
        cin>>n>>j>>k;
        vector<int> nums(n);
        int element;
        
        for(int i=0; i<n; i++) {
            cin>>nums[i];
        }
        element = nums[j-1];
        
        sort(nums.begin(), nums.end());
        
        if(element == nums[n-1] || k>1) {
            cout<<"YES"<<endl;
            continue;
        } else {
            cout<<"NO"<<endl;
            continue;
        }
    }
    return 0;
}