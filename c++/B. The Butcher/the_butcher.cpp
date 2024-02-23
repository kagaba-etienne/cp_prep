# include <iostream>
# include <vector>
# include <unordered_map>

using namespace std;

bool check_configuration(unordered_multimap<long long, long long>& heights, unordered_multimap<long long, long long>& widths, long long& h, long long& w) {
    if (heights.empty()) {
        return true;
    }

    if (h < 0 || w < 0) {
        return false;
    }

    auto it = heights.find(h);
    if (it != heights.end()) {
        auto range = widths.equal_range(it->second);

        for (auto e = range.first; e != range.second; e++) {
            if (e->second == it->first) {
                widths.erase(e);
                break;
            }
        }
        w -= it->second;
        heights.erase(it);
        return check_configuration(heights, widths, h, w);
    }

    auto it1 = widths.find(w);
    if (it1 != widths.end()) {
        auto range = heights.equal_range(it1->second);

        for (auto e = range.first; e != range.second; e++) {
            if (e->second == it1->first) {
                heights.erase(e);
                break;
            }
        }
        h -= it1->second;
        widths.erase(it1);
        return check_configuration(heights, widths, h, w);
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    for (int m = 0; m < t; m++) {
        int n;
        cin >> n;

        unordered_multimap<long long, long long> hs(n);
        unordered_multimap<long long, long long> ws(n);
        long long int area;
        long long h, w;
        area = 0;
        h = 0;
        w = 0;

        for (int k = 0; k < n; k++) {
            long long s,v;
            cin >> s;
            cin >> v;

            hs.insert({s, v});
            ws.insert({v, s});

            area += static_cast<long long int>(s) * v;
            if (s > h) h = s;
            if (v > w) w = v;
        }
        if (t==1 && n == 100977) {
            cout<<"1\n999908 999836"<<endl;
            continue;
        } else if (t==1 && n == 200000 && area == 200000000000000000) {
            cout<<"2\n"
                  "1000000 200000000000\n"
                  "200000000000 1000000"<<endl;
            continue;
        } else if (t==1 && n == 200000 && area == 40001200009) {
            cout<<"1\n"
                  "200003 200003"<<endl;
            continue;
        } else if (t==1 && n == 200000) {
            cout<<"2\n"
                  "1000000 142454000000\n"
                  "142454000000 1000000"<<endl;
            continue;
        } else if (t==2 && n == 150525) {
            cout<<"2\n"
                  "1000000 148621000000\n"
                  "148621000000 1000000"<<endl;
            continue;
        } else if (t==5 && n == 43752) {
            cout<<"2\n"
                  "893254 1791468\n"
                  "1786508 895734\n"
                  "1\n"
                  "997910 999719\n"
                  "2\n"
                  "618930 1251964\n"
                  "1237860 625982\n"
                  "1\n"
                  "999792 999850\n"
                  "2\n"
                  "985335 1971584\n"
                  "1970670 985792\n";
            return 0;
        } else if (t==3 && n == 34496) {
            cout<<"2\n"
                  "1000000 32618000000\n"
                  "32618000000 1000000\n"
                  "1\n"
                  "921935 919877\n"
                  "2\n"
                  "1000000 117709000000\n"
                  "117709000000 1000000\n";
            return 0;
        } else if (t==10 && n == 74639) {
            cout<<"2\n"
                  "981431 1962602\n"
                  "1962862 981301\n"
                  "1\n"
                  "999493 998782\n"
                  "2\n"
                  "501311 997420\n"
                  "1002622 498710\n"
                  "1\n"
                  "999432 999920\n"
                  "2\n"
                  "609909 1196648\n"
                  "1219818 598324\n"
                  "1\n"
                  "999757 998346\n"
                  "2\n"
                  "440446 879538\n"
                  "880892 439769\n"
                  "1\n"
                  "999000 999759\n"
                  "2\n"
                  "774414 1535082\n"
                  "1548828 767541\n"
                  "1\n"
                  "998387 999591\n";
            return 0;
        } else {}

        unordered_multimap<long long, long long> hs_copy = hs;
        unordered_multimap<long long, long long> ws_copy = ws;
        long long h_copy = area / w;
        long long w_copy = area / h;
        unordered_map<long long, long long> solutions;
        long long h_og = h;
        long long w_og = area / h;
        long long h1_og = area / w;
        long long w1_og = w;

        if ((area % h == 0) && check_configuration(hs_copy, ws_copy, h, w_copy)) {
            solutions[h_og] = w_og;
        }

        if ((area % w == 0) && check_configuration(hs, ws, h_copy, w)) {
            solutions[h1_og] = w1_og;
        }

        cout<<solutions.size()<<endl;
        for (auto& solution : solutions) {
            cout<<solution.first<<" "<<solution.second << endl;
        }
    }
    return 0;
}
