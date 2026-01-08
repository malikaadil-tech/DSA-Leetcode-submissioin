class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MIN));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                int prod = nums1[i-1] * nums2[j-1];

                int extend = (dp[i-1][j-1] == INT_MIN)
                             ? INT_MIN
                             : dp[i-1][j-1] + prod;

                dp[i][j] = max({
                    prod,        // start new
                    extend,      // extend safely
                    dp[i-1][j],  // skip nums1
                    dp[i][j-1]   // skip nums2
                });
            }
        }
        return dp[n][m];
    }
};
