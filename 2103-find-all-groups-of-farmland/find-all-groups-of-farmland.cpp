#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& land, int i, int j, int& c, int& d) {
        int n = land.size();
        int m = land[0].size();
        if (i >= 0 && i < n && j >= 0 && j < m && land[i][j] == 1) {
            land[i][j] = 0;
            if (i > c || (i == c && j > d)) {
                c = i;
                d = j;
            }
        } else {
            return;
        }
        dfs(land, i + 1, j, c, d);
        dfs(land, i - 1, j, c, d);
        dfs(land, i, j + 1, c, d);
        dfs(land, i, j - 1, c, d);
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        vector<vector<int>> result;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (land[i][j] == 1) {
                    int a = i;
                    int b = j;
                    int c = INT_MIN;
                    int d = INT_MIN;
                    dfs(land, i, j, c, d);
                    result.push_back({a, b, c, d});
                }
            }
        }

        return result;
    }
};