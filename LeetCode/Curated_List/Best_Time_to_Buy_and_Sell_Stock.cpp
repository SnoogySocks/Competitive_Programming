// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/
// 10/12/2021

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int buy, sell;
        buy = sell = prices[0];
        for (int i = 1; i<prices.size(); ++i) {
            if (prices[i]<buy) {
                buy = prices[i];
                sell = prices[i];
            } else if (prices[i]>sell) {
                sell = prices[i];
                maxProfit = max(maxProfit, sell-buy);
            }
        }
        return maxProfit;
    }
};
