// https://leetcode.com/problems/coin-change/
// October 14 2021

class Solution {
public:
    const int mxN = INT_MAX-1;
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, mxN);
        dp[0] = 0;
        for (int total = 1; total<=amount; ++total) {
            for (const int& coin: coins) {
                if (total-coin<0) continue;
                dp[total] = min(dp[total], dp[total-coin]+1);
            }
        }
        
        return dp[amount]!=mxN?dp[amount]:-1;
    }
};
