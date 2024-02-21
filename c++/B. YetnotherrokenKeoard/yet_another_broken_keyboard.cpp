# include <iostream>
# include <vector>
# include <string>
# include <cctype>
# include <algorithm>

int main() {
    int t;
    std::cin>>t;
    std::vector<std::string> lines;

    for(int j=0; j<t; j++) {
        std::string line;
        std::cin>>line;
        lines.push_back(line);
    }

    for (std::string& line: lines) {
        std::vector<int> lower;
        std::vector<int> upper;

        for (int k=0; k<line.size(); k++) {
            if (line[k] == 'b') {
                if (!lower.empty()) {
                    lower.pop_back();
                }
            } else if (line[k] == 'B') {
                if (!upper.empty()) {
                    upper.pop_back();
                }
            } else if (std::islower(line[k])) {
                lower.push_back(k);
            } else {
                upper.push_back(k);
            }
        }

        lower.insert(lower.end(), upper.begin(), upper.end());
        std::sort(lower.begin(), lower.end());
        for (int& i: lower) {
            std::cout<<line[i];
        }
        std::cout<<std::endl;
    }
}