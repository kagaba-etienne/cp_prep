#include<bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> length(nums.size(), 1);
    map<int, int> heads;
    int max_len = 0;

    for(int i=0; i<nums.size(); i++) {
        auto it =  heads.lower_bound(nums[i]);

        for(auto it1 = heads.begin(); it1 != it; it1++) {
            length[i] = max(length[i], length[it1->second]+1);
        }

        auto it2 = heads.find(nums[i]);

        if(it2 != heads.end()) {
            if(length[it2->second] < length[i]) it2->second = i;
        } else {
            heads.insert(make_pair(nums[i], i));
        }

        max_len = max(max_len, length[i]);
    }

    return max_len;
}

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout<<lengthOfLIS(nums)<<endl;
    return 0;
}