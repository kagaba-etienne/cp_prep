#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string word;
    vector<char> v;
    cin>>word;
    for(char& j: word) {
        int num = static_cast<int>(j);
        switch (num) {
            case 65:
            case 69:
            case 73:
            case 79:
            case 85:
            case 89:
            case 97:
            case 101:
            case 105:
            case 111:
            case 117:
            case 121:
                continue;
        }
        if (num>64 && num<91) {
            v.push_back('.');
            v.push_back(static_cast<char>(num + 32));
            continue;
        }
        v.push_back('.');
        v.push_back(j);
    }

    for (char i: v) {
        cout<<i;
    }

    return 0;
}