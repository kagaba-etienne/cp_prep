#include<iostream>
#include<vector>

using namespace std;

void insertion_sort(vector<int>& a) {
    for(int j=1; j<a.size(); j++) {
        int current_value = a[j];
        int i = j-1;
        while(i >= 0 && a[i] > current_value) { // Change the comparator to < for sorting in descending order!!
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = current_value; 
    }
    return;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i=0; i<n; i++) {
        cin>> arr[i];
    }

    insertion_sort(arr);
    
    for(auto j: arr) {
        cout << j << " ";
    }

    cout << endl;

    return 0;
}