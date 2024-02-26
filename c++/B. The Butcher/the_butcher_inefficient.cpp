# include <iostream>
# include <vector>
# include <map>

using namespace std;

bool check_configuration(multimap<long long, long long>& rects, long long& h, long long& w) {
    if (rects.empty()) {
        return true;
    }

    auto it = rects.find(h);
    if (it != rects.end()) {
        w -= it->second;
        rects.erase(it);
        return check_configuration(rects, h, w);
    }

    for (auto it1 = rects.rbegin(); it1 != rects.rend(); ++it1) {
        if (it1->second == w) {
            h -= it1->first;
            auto forward_it = next(it1.base(), -1);
            rects.erase(forward_it);
            return check_configuration(rects, h, w);
        }
    }

    return false;
}

int main() {
    int t;
    cin >> t;
    for (int m = 0; m < t; m++) {
        int n;
        cin >> n;

        multimap<long long, long long> rects;
        long long int area;
        long long h, w;
        area = 0;
        h = 0;
        w = 0;

        for (int k = 0; k < n; k++) {
            long long s,v;
            cin >> s;
            cin >> v;

            rects.insert({s, v});

            area += static_cast<long long int>(s) * v;
            if (s > h) h = s;
            if (v > w) w = v;
        }

        multimap<long long, long long> rects_copy = rects;
        long long h_copy = (area % w == 0)? area / w : 0;
        long long w_copy = (area % h == 0)? area / h : 0;
        map<long long, long long> solutions;
        long long h_og = h;
        long long w_og = area / h;
        long long h1_og = area / w;
        long long w1_og = w;

        if ((w_copy != 0) && check_configuration(rects_copy, h, w_copy)) {
            solutions[h_og] = w_og;
        }

        if (solutions.empty()) {
            cout << 1 << endl <<h_copy <<" " << w << endl;
            continue;
        }

        if ((h_copy != 0) && check_configuration(rects, h_copy, w)) {
            solutions[h1_og] = w1_og;
        }

        cout<<solutions.size()<<endl;
        for (auto& solution : solutions) {
            cout<<solution.first<<" "<<solution.second << endl;
        }
    }
    return 0;
}