// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/submissions/
// October 12 2021

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l, r, m;
        l = 0;
        r = nums.size()-1;
        while (l<r && nums[l]>nums[r]) {
            m = l+(r-l)/2;
            if (nums[m]<nums[l]) {
                r = m;
            } else if (nums[r]<=nums[m]) {
                l = m+1;
            }
        }
        return nums[l];
        
        // sort(nums.begin(), nums.end());
        // return nums[0];
    }
};
