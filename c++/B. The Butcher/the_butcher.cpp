# include <iostream>
# include <map>

using namespace std;

void stabilize_indices(map<long long, map<long long, int>>& h_idx, map<long long, map<long long, int>>& w_idx, long long& h, long long& w) {
    auto it = h_idx.find(h);
    auto elem = it->second.begin();
    w -= elem->first;
    elem->second -= 1;

    auto it2 = w_idx.find(elem->first);
    auto elem2 = it2->second.find(h);
    elem2->second -= 1;

//   Remove w_h item if times are less than 1
    if (elem2->second < 1) {
        it2->second.erase(elem2);
    } else {
        it2->second[h] = elem2->second;
    }

//  Remove w if it is empty
    if (it2->second.empty()) {
        w_idx.erase(it2);
    } else {
        w_idx[elem->first] = it2->second;
    }

//  Remove h_w item if times are less than 1
    if (elem->second < 1) {
        it->second.erase(elem);
    } else {
        it->second[elem->first] = elem->second;
    }


//  Remove h if it is empty
    if (it->second.empty()) {
        h_idx.erase(it);
    } else {
        h_idx[h] = it->second;
    }
}


bool check_configuration(map<long long, map<long long, int>>& h_idx, map<long long, map<long long, int>>& w_idx, long long& h, long long& w) {
    if (h_idx.empty()) {
        return true;
    }

    auto it = h_idx.find(h);
    if (it != h_idx.end()) {
        stabilize_indices(h_idx, w_idx, h, w);
        return check_configuration(h_idx, w_idx, h, w);
    }
    auto it3 = w_idx.find(w);
    if (it3 != w_idx.end()) {
        stabilize_indices(w_idx, h_idx, w, h);
        return check_configuration(h_idx, w_idx, h, w);
    }

    return false;
}


int main() {
    int t;
    cin >> t;
    for (int m = 0; m < t; m++) {
        int n;
        cin >> n;

        map<long long, map<long long, int>> h_index;
        map<long long, map<long long, int>> w_index;
        long long int area;
        long long h, w;
        area = 0;
        h = 0;
        w = 0;
//        Reading [h, w]'s
        for (int k = 0; k < n; k++) {
            long long s,v;
            cin >> s;
            cin >> v;

            auto h_dup = h_index.find(s);
            if (h_dup != h_index.end()) {
                auto h_w_dup = h_dup->second.find(v);
                if (h_w_dup != h_dup->second.end()) {
                    h_dup->second[v] += 1;
                } else {
                    h_dup->second[v] = 1;
                }
                h_index[s] = h_dup->second;
            } else {
                h_index[s].insert({v, 1});
            }

            auto w_dup = w_index.find(v);
            if (w_dup != w_index.end()) {
                auto w_h_dup = w_dup->second.find(s);
                if (w_h_dup != w_dup->second.end()) {
                    w_dup->second[s] += 1;
                } else {
                    w_dup->second[s] = 1;
                }
                w_index[v] = w_dup->second;
            } else {
                w_index[v].insert({s, 1});
            }

            area += static_cast<long long int>(s) * v;
            if (s > h) h = s;
            if (v > w) w = v;
        }

        map<long long, map<long long, int>> h_index_copy = h_index;
        map<long long, map<long long, int>> w_index_copy = w_index;
        long long h_copy = (area % w == 0)? area / w : 0;
        long long w_copy = (area % h == 0)? area / h : 0;
        map<long long, long long> solutions;
        long long h_og = h;
        long long w_og = area / h;
        long long h1_og = area / w;
        long long w1_og = w;

        if ((w_copy != 0) && check_configuration(h_index_copy, w_index_copy, h, w_copy)) {
            solutions[h_og] = w_og;
        }

        if (solutions.empty()) {
            cout << 1 << endl <<h_copy <<" " << w << endl;
            continue;
        }

        if ((h_copy != 0) && check_configuration(h_index, w_index, h_copy, w)) {
            solutions[h1_og] = w1_og;
        }

        cout<<solutions.size()<<endl;
        for (auto& solution : solutions) {
            cout<<solution.first<<" "<<solution.second << endl;
        }
    }
    return 0;
}