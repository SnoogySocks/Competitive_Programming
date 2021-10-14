// https://leetcode.com/problems/longest-common-subsequence/
// October 14 2021

class Solution {
public:
//     int longestCommonSubsequence(string text1, string text2) {
//         /*
//             dp[i][j] = longest common subsequence using
//                        the first i letters from text1 and
//                        the first j letters from text2
//         */
//         vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1));
        
//         for (int i = 1; i<=text1.size(); ++i) {
//             for (int j = 1; j<=text2.size(); ++j) {
//                 if (text1[i-1]==text2[j-1]) {
//                     dp[i][j] = dp[i-1][j-1]+1;
//                 } else {
//                     dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
//                 }
//             }
//         }
        
//         // for (int i = 1; i<=text1.size(); ++i) {
//         //     for (int j = 1; j<=text2.size(); ++j) {
//         //         cout<<dp[i][j]<<' ';
//         //     }
//         //     cout<<'\n';
//         // }
        
//         return dp.back().back();
//     }
    
    // Top-down approach for more efficient memory
    int longestCommonSubsequence(string text1, string text2) {
        /*
            dp[i][j] = longest common subsequence using
                       the first i letters from text1 and
                       the first j letters from text2
        */
        vector<vector<int>> dp(2, vector<int>(text2.size()+1));
        for (int i = 1; i<=text1.size(); ++i) {
            for (int j = 1; j<=text2.size(); ++j) {
                if (text1[i-1]==text2[j-1]) {
                    dp[1][j] = dp[0][j-1]+1;
                } else {
                    dp[1][j] = max(dp[1][j-1], dp[0][j]);
                }
            }
            // Move everything over to the first row
            for (int j = 1; j<=text2.size(); ++j) {
                dp[0][j] = dp[1][j];
                dp[1][j] = 0;
            }
        }
        
        // for (int i = 1; i<=text1.size(); ++i) {
        //     for (int j = 1; j<=text2.size(); ++j) {
        //         cout<<dp[i][j]<<' ';
        //     }
        //     cout<<'\n';
        // }
        
        return dp[0].back();
    }
};

