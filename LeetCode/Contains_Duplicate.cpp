// https://leetcode.com/problems/contains-duplicate/submissions/
// 10/12/2021

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // unordered_set<int> seen;
        // seen.reserve(nums.size());
        // for (int n: nums) {
        //     if (seen.count(n)) {
        //         return true;
        //     }
        //     seen.insert(n);
        // }
        // return false;
        sort(nums.begin(), nums.end());
        for (int i = 1; i<nums.size(); ++i) {
            if (nums[i-1]==nums[i]) {
                return true;
            }
        }
        return false;
    }
};
