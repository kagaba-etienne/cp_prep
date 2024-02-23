#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int l = 0; l < t; l++) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; i++) {
            int j;
            cin >> j;
            if (j == 0) {
                continue;
            }
            a.push_back(i);
        }
        int sum=0;
        for (int k = 0; k < a.size()-1; k++) {
            if ((a[k + 1] - a[k]) > 1) {
                sum += a[k+1] - a[k] - 1;
            }
        }
        cout<<sum<<endl;
    }
}