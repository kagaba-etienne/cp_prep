# include <iostream>
# include <vector>
# include <unordered_map>

using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> e;

        for (int j = 0; j < nums.size(); j++) {
            int complement = target - nums[j];
            if (e.find(complement) != e.end()) {
                return {e[complement], j};
            }
            e[nums[j]] = j;
        }

        return {};
    }
};

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    // Expected output: 01 or 10

    for(int& i: Solution::twoSum(nums, target)) {
        cout<<i;
    }

    return 0;
}