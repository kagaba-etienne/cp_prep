#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(vector<ll>& nums) {
    ll n = nums.size();
    ll sum = n*(n+1)/2;

    for(ll num : nums) {
        sum -= num;
    }

    return sum;
}

int main() {
    std::vector<ll> nums = {0,1,2,4,5,6};

    std::cout<<solve(nums);
}