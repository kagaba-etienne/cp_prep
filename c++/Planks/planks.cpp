#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int solve(vector<int> wood) {
    map<int, int> wood_count;
    int max_planks = 0;

    for(int i=0; i < wood.size(); i++) {
        auto it = wood_count.find(wood[i]);

        if(it == wood_count.end()) {
            wood_count.insert(make_pair(wood[i], 1));
        } else {
            wood_count[wood[i]] += 1;
        }
    }
    max_planks = wood_count[wood[0]];

    auto current = wood_count.begin();
    ++current;
    for(;current != wood_count.end(); current++) {
        auto sub = current;
        --sub;
        int sum = current->second;

        while((double)sub->first >= (double)(current->first)/2) {
            auto it = wood_count.find(current->first-sub->first);

            if(it != wood_count.end() && it == sub) {
                sum += it->second/2;
            } else if(it != wood_count.end()) {
                sum += min(it->second, sub->second);
            }

            if(sub == wood_count.begin()) {
                break;
            } else {
                --sub;
            }
        }

        max_planks = max(sum, max_planks);
    }
    
    return max_planks;
}

int main() {
    vector<int> pieces = {1, 1, 1, 2, 2, 2, 3};
    cout<<solve(pieces);
}