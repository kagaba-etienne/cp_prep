#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    vector<int> v;

    for(int i =0; i<=2; i++) {
        int num;
        cin>>num;
        v.push_back(num);
    }

    cout << static_cast<long long>(ceil(static_cast<double>(v[0]) / v[2]) * ceil(static_cast<double>(v[1]) / v[2])) << endl;
    return 0;
}
