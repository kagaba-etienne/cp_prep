#include<iostream>
#include<vector>

using namespace std;

vector<int> add_bin(vector<int>& a, vector<int>& b) {
    int max_len = a.size()>b.size()? a.size(): b.size();
    int min_len = a.size()<b.size()? a.size(): b.size();
    vector<int> c(max_len+1, 0);
    int carry = 0;
    int i;

    vector<int>* ptr_to_max = a.size()>b.size()? &a: &b;
    vector<int>* ptr_to_min = a.size()<b.size()? &a: &b;

    for(i=max_len-1; i>=max_len-min_len; i--) {
        int sum = ((*ptr_to_max)[i] ^ (*ptr_to_min)[i-max_len+min_len]) ^ carry;
        c[i+1] = sum;
        carry = (
            (*ptr_to_max)[i] & (*ptr_to_min)[i-max_len+min_len]
            | (*ptr_to_min)[i-max_len+min_len] & carry
            | (*ptr_to_max)[i] & carry
        );
    }

    for(;i>=0;i--) {
        int sum = (*ptr_to_max)[i] ^ carry;
        c[i+1] = sum;
        carry = (*ptr_to_max)[i] & carry;
    }

    c[0] = carry;

    return c;
}

int main() {
    vector<int> a = {1, 1, 1, 1, 1, 1, 1};
    vector<int> b = {1, 1, 1, 1, 1, 1, 1};

    vector<int> c = add_bin(a, b);

    for(auto i: c) {
        cout<< i <<" ";
    }

    cout<<endl;
    return 0;
}