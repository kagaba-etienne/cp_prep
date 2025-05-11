#include<bits/stdc++.h>

using namespace std;

void find_new_center(int& cntr, int& rd, vector<int>& pldrm, int& j) {
    for(int i = 0; i < rd; i++) {
        //is it fully contained?
        int prv_cntr = cntr-i-1;
        int prv_rd = pldrm[prv_cntr]/2;
        if(prv_cntr-prv_rd >= cntr-rd) pldrm[cntr+i+1] = prv_rd*2 + 1;
        
        // is it at the edge?
        if(prv_cntr-prv_rd == cntr-rd) {
            cntr += i+1;
            rd = prv_rd;
            return;
        }
    }

    cntr = j;
    rd = 0;
}

tuple<int, int> longestPalindrome(string s) {
    bool success = false;
    int rd = 0, cntr = 0;
    int mx_rd = 0, mx_cntr = 0;
    int n = s.length();
    vector<int> pldrm(n, 1);

    for(int i = 0; i < n; i++) {
        char curr_chr = s[cntr+rd+1];

        if(success && cntr-rd-1 >= 0 && curr_chr == s[cntr-rd-1]) {
            // move the boundaries
            ++rd;
            if(rd >= mx_rd) {
                mx_rd = rd;
                mx_cntr = cntr;
            }

            pldrm[cntr] = 2*rd + 1;
        } else{
            success = false;
            find_new_center(cntr, rd, pldrm, i);
        }


        if (!success && cntr-rd-1 >= 0 && s[cntr-rd-1] == s[cntr+rd+1]) {
            success = true;
            ++rd;
            if(rd >= mx_rd) {
                mx_rd = rd;
                mx_cntr = cntr;
            }
            pldrm[cntr] = 2*rd+1;
        }

        if(cntr+rd == n-1) break;
    }

    return {mx_cntr-mx_rd, 2*mx_rd+1};
}

string solve(string s) {
    ostringstream b;
    b << '$';
    for(char i: s) {
        b << i << '$';
    }

    string c = b.str();
    tuple<int, int> even = longestPalindrome(c);
    tuple<int, int> odd = longestPalindrome(s);

    if(get<1>(even)/2 >= get<1>(odd)) {
        ostringstream d;
        for(int k = get<0>(even); k < get<0>(even)+get<1>(even); k++) {
            if(k%2) d << c[k];
        }
        return d.str();
    } else {
        return s.substr(get<0>(odd), get<1>(odd));
    }
}

int main() {
    string m = "aacabdkacaa";
    cout<<solve(m)<<endl;
    return 0;
}