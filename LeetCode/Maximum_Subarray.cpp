// https://leetcode.com/problems/maximum-subarray/submissions/
// 12 October 2021

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum, curSum;
        maxSum = curSum = nums[0];
        for (int i = 1; i<nums.size(); ++i) {
            curSum = max(nums[i], curSum+nums[i]);
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};
