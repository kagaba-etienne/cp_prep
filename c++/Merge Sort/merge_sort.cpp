#include<iostream>
#include<vector>
#include<limits>

using namespace std;

#define REP(i,x,y) for(int i=(x); i<(y); i++)

#define PRINT(y) for(auto x: (y)) cout<<x<<" "

#define MERGE(x, y, z) merge_with_sentinels((x), (y), (z))


//Merge without Sentinels
void merge_without_sentinels(vector<int>::iterator p, vector<int>::iterator q, vector<int>::iterator r) {
    int infinity = numeric_limits<int>::max();
    int n1 = (q-p);
    int n2 = (r-q);
    
    vector<int> le(n1), ri(n2);

    REP(i, 0, n1) le[i] = *(p+i);
    REP(j, 0, n2) ri[j] = *(q+j);

    int i = 0;
    int j = 0;

    REP(k, 0, r-p) {
        if(i<n1 && j<n2 && le[i] > ri[j]) {
            *(p+k) = ri[j];
            j++;
        } else if(i<n1 && j>=n2) {
            *(p+k) = le[i];
            i++;
        }else if(j<n2 && i>=n1) {
            *(p+k) = ri[j];
            j++;
        } else {
            *(p+k) = le[i];
            i++;
        }
    }

}


// Merge with Sentinels
void merge_with_sentinels(vector<int>::iterator p, vector<int>::iterator q, vector<int>::iterator r) {
    int infinity = numeric_limits<int>::max();
    int n1 = (q-p);
    int n2 = (r-q);
    
    vector<int> le(n1), ri(n2);

    REP(i, 0, n1) le[i] = *(p+i);
    REP(j, 0, n2) ri[j] = *(q+j);

    le.push_back(infinity);
    ri.push_back(infinity);

    int i = 0;
    int j = 0;
    REP(k, 0, r-p) {
        if(le[i] > ri[j]) {
            *(p+k) = ri[j];
            j++;
        } else {
            *(p+k) = le[i];
            i++; 
        }
    }
    return;
}


void merge_sort(vector<int>::iterator begin, vector<int>::iterator end) {
    auto middle = begin + (end - begin)/2;

    if(begin == end-1) return;

    merge_sort(begin, middle);
    merge_sort(middle, end);

    MERGE(begin, middle, end);
    return;
}

int main() {
    vector<int> arr = {4, 3, 1, -29, 4, -20, 75, 35, 12, -90, -98, -2, 3};
    merge_sort(arr.begin(), arr.end());

    PRINT(arr);

    return 0;
}