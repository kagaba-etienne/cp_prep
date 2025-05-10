#include<bits/stdc++.h>

using namespace std;

string longestPalindrome(string s) {
    bool success = false;
    bool same = false;
    int lvl = 0, r = 0, tmp_r = 0, tmp_l = 0, l = 0;
    unordered_set<char, vector<int>> occrnc;
    unordered_map<int, unordered_set<int>> pldrm;

    if(s.length() <= 2) {
        if (s.length() == 2 && s[0] == s[1]) return s;
        return string(1, s[0]);
    }

    pldrm.insert(make_pair<int, unordered_set<int>>(0, {0}));
    pldrm.insert(make_pair<int, unordered_set<int>>(1, {1}));

    if (s[0] == s[1]) {
        r = 1;
        same = true;
        pldrm[0].insert(1);
    }

    vector<char> tmp = {s[0], s[1]};

    for(int i= 2; i < s.length(); i++) {
        char curr_chr = s[i];



        if(success && i-lvl-2 >= 0 && s[i] == tmp[i-lvl-2]) {
            if(tmp[i-1] != curr_chr) same = false;
            lvl += 2;
            --tmp_l;
            ++tmp_r;

            auto it = pldrm.find(tmp_l);

            if(it != pldrm.end()) {
                it->second.insert(tmp_r);
            } else {
                pldrm.insert(make_pair(tmp_l, unordered_set<int>({tmp_r})));
            }

            if ((tmp_r - tmp_l) >= (r - l)) {
                l = tmp_l;
                r = tmp_r;
            }
        } else if (success && curr_chr == tmp[tmp_l] && pldrm[tmp_l+1].find(tmp_r) != pldrm[tmp_l+1].end()) {
            ++lvl;
            ++tmp_r;

            auto it = pldrm.find(tmp_l);
            
            if(it != pldrm.end()) {
                it->second.insert(tmp_r);
            } else {
                pldrm.insert(make_pair(tmp_l, unordered_set<int>({tmp_r})));
            }

            if ((tmp_r - tmp_l) >= (r - l)) {
                l = tmp_l;
                r = tmp_r;
            }
        } else  {
            lvl = 0;
            success = false;
        }

        if ((curr_chr == tmp[i-1] || curr_chr == tmp[i-2]) && lvl == 0) {
            success = true;

            // if(i+1 < s.length() && tmp[i-2] == tmp[i-1] && s[i+1] == curr_chr) {
            //     lvl = 1;
            //     same = true;
            // } else {
            //     curr_chr == tmp[i-2] ? lvl = 2 : lvl = 1;
            //     lvl==1? same = true : same = false;
            // }
            curr_chr == tmp[i-2] ? lvl = 2 : lvl = 1;
            lvl==1? same = true : tmp[i-2] == tmp[i-1] ? same = true : same = false;

            tmp_l = i - lvl;
            tmp_r = i;

            auto it = pldrm.find(tmp_l);
            
            if(it != pldrm.end()) {
                it->second.insert(tmp_r);
            } else {
                pldrm.insert(make_pair(tmp_l, unordered_set<int>({tmp_r})));
            }

            if ((tmp_r - tmp_l) >= (r - l)) {
                l = tmp_l;
                r = tmp_r;
            }
        }

        if(curr_chr == tmp[l]) {
            
        }

        tmp.push_back(curr_chr);
    }

    return s.substr(l,(r-l+1));
}

int main() {
    string m = "ababababababa";
    cout<<longestPalindrome(m)<<endl;;

    return 0;
}