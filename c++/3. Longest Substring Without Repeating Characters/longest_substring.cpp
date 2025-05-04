#include<bits/stdc++.h>

using namespace std;

int length_of_longest_substring(string s) {
    int max_len = 0, temp_len = 0, start = 0;
    unordered_map<char, int> window;

    for(int i = 0; i < s.size(); i++) {
        auto it = window.find(s[i]);

        if(it == window.end()) {
            temp_len++;
            max_len = max(max_len, temp_len);
            window.insert(make_pair(s[i], i));
        } else {
            for(int j = start; j< window[s[i]]; j++) window.erase(s[j]);

            temp_len = temp_len + start - window[s[i]];
            start = window[s[i]] + 1;
            window[s[i]] = i;
        }
    }

    return max_len;
}

int main() {
    string s = "hello world!";
    string b = "nbcnuweuponrhczmck";

    cout<<length_of_longest_substring(b);
    return 0;
}