// https://leetcode.com/problems/longest-increasing-subsequence/
// October 14 2021

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // vector<int> lengths(nums.size(), 1);
        // int maxLength = 1;
        // for (int i = 1; i<lengths.size(); ++i) {
        //     for (int j = i-1; j>=0; --j) {
        //         if (nums[j]<nums[i]) {
        //             lengths[i] = max(lengths[i], lengths[j]+1);
        //         }
        //     }
        //     maxLength = max(maxLength, lengths[i]);
        // }
        // return maxLength;
        vector<int> dp;
        dp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            if (num > dp[dp.size() - 1]) {
                dp.push_back(num);
            } else {
                auto lower = lower_bound(dp.begin(), dp.end(), num);
                *lower = num;
            }
        }
        return dp.size();
    }
};
