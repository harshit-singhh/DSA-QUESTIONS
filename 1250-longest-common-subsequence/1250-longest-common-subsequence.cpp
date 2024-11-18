class Solution {
public:
    int dp[1005][1005]; // Adjust size for offsets

    int solve(string& str1, string& str2, int index1, int index2) {
        // Base case: if either string is exhausted
        if (index1 == -1 || index2 == -1) return 0;

        // Apply consistent offset
        int offset1 = index1 + 3;
        int offset2 = index2 + 3;

        // Check memoization
        if (dp[offset1][offset2] != -1) return dp[offset1][offset2];

        // Calculate LCS
        int matching = 0, notmatching = 0;

        if (str1[index1] == str2[index2]) {
            matching = 1 + solve(str1, str2, index1 - 1, index2 - 1);
        } else {
            notmatching = max(
                solve(str1, str2, index1 - 1, index2), 
                solve(str1, str2, index1, index2 - 1)
            );
        }

        // Store result in `dp` using offset
        return dp[offset1][offset2] = max(matching, notmatching);
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        // Initialize `dp` with -2
        memset(dp, -1, sizeof(dp));

        return solve(text1, text2, n - 1, m - 1);
    }
};
