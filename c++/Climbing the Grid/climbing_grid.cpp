#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <limits>
#include <algorithm>
using namespace std;


/**
 * Problem statement:
 * 
 * You are given an m x n array. Given that a score to move from cell c1 to cell c2 is c2-c1 and you can either move to the cell directly below (adjacent) or to the right(not necessarily adjacent) 
 * 
 * Given that you have to make at least one move.
 * What is the maximum attainable score?
 * 
 * 2 < m,n < 1000
 * 
 * Each element in the array ranges between 1 and 10^5
 * 
 * 
 * Solution Complexity: O(m*n);
 */

class Solution {
public:
    int solution(vector<vector<int>>& k) {
        int max_val = numeric_limits<int>::min();
        
        vector<vector<int>> grid(k.size(), vector<int>(k[0].size(), max_val));

        for(int i = k.size()-1; i>=0; i--) {
            set<int> right;
            map<int, int> right_max;
            for(int j = k[i].size()-1; j>=0; j--) {
                // if on the right end
                if(j+1 == k[i].size()) {
                    if(i+1 == k.size()) {
                        grid[i][j] = 0;
                        right.insert(k[i][j]);
                        continue;
                    }

                    grid[i][j] = k[i+1][j] - k[i][j];
                    max_val = max(grid[i][j], max_val);
                    right_max.insert(make_pair(grid[i][j]+k[i][j], j));
                    continue;
                }

                // if on the bottom
                if(i+1 == k.size()) {
                    grid[i][j] = *(right.rbegin()) - k[i][j];
                    max_val = max(grid[i][j], max_val);
                    right.insert(k[i][j]);
                    continue;
                }

                // else where
                grid[i][j] = max(k[i][right_max.rbegin()->second] - k[i][j], right_max.rbegin()->first - k[i][j]);
                grid[i][j] = max(grid[i][j], k[i+1][j] - k[i][j]);
                grid[i][j] = max(grid[i][j], k[i+1][j]-k[i][j] + grid[i+1][j]);
                max_val = max(grid[i][j], max_val);
                right_max.insert(make_pair(grid[i][j]+k[i][j], j));
                continue;
            }
            right_max.clear();
        }
        return max_val;
    }
};



/**
R E A D M E
DO NOT CHANGE the code below, we use it to grade your submission. If changed your submission will be failed automatically.
**/

int main()
{
    string sMtx;
    getline(cin, sMtx);

    // sample input [[7,5,3],[6,4,2]], expected output -1
     
    vector<vector<int>> mtx;
    stringstream ss(sMtx.substr(2, sMtx.size() - 4));

    string segment;
    while (getline(ss, segment, ']')) {
        stringstream row_ss(segment.substr(segment[0] == ',' ? 2 : 0));
        string number;
        vector<int> row;
        while (getline(row_ss, number, ',')) {
            row.push_back(stoi(number));
        }
        mtx.push_back(row);
    }

    Solution solution;
    cout << solution.solution(mtx);

    return 0;
}