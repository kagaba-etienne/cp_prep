#include<bits/stdc++.h>

using namespace std;

string longestPalindrome(string s) {
    int r = 0, l = 0;
    unordered_map<char, vector<int>> occrnc;
    unordered_map<int, unordered_set<int>> pldrm;

    if(s.length() <= 2) {
        if (s.length() == 2 && s[0] == s[1]) return s;
        return string(1, s[0]);
    }

    pldrm.insert(make_pair<int, unordered_set<int>>(0, {0}));
    pldrm.insert(make_pair<int, unordered_set<int>>(1, {1}));
    occrnc.insert(make_pair(s[0], vector<int>({0})));

    if (s[0] == s[1]) {
        r = 1;
        pldrm[0].insert(1);
        occrnc[s[0]].push_back(1);
    } else {
        occrnc.insert(make_pair(s[1], vector<int>({1})));
    }

    for(int i= 2; i < s.length(); i++) {
        char curr_chr = s[i];
        auto it = occrnc.find(curr_chr);

        pldrm.insert(make_pair(i, unordered_set<int>({i})));

        if(it == occrnc.end()) {
            occrnc.insert(make_pair(curr_chr, vector<int>({i})));
            continue;
        }

        for(auto j: it->second) {
            auto it1 = pldrm.find(j+1);
            if(it1 == pldrm.end()) continue;

            if(it1->second.find(i-1) != it1->second.end() || i-j == 1) {
                pldrm[j].insert(i);
                if((i-j) > (r-l)) {
                    r = i;
                    l = j;
                }
                continue;
            }
        }

        occrnc[curr_chr].push_back(i);
    }
    return s.substr(l,(r-l+1));
}

int main() {
    string m = "ababababababa";
    cout<<longestPalindrome(m)<<endl;

    return 0;
}