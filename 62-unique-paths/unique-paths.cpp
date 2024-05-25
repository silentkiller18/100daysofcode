class Solution {
public:
    int uniquePaths(int m, int n) {
    vector<int> dp(m);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j - 1 >= 0) dp[j] += dp[j - 1];
        }
    }

    return dp.back();
}
};