// https://leetcode.com/problems/missing-number/
// Ocotber 14 2021

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int t = 0;
        for (int i = 0; i<nums.size(); ++i) {
            t += nums[i];
        }
        return (nums.size()*(nums.size()+1)>>1)-t;
    }
};
