// https://leetcode.com/problems/two-sum/submissions/
// 10/12/2021

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> compliments;
        for (int i = 0; i<nums.size(); ++i) {
            if (compliments.count(nums[i])) {
                return { compliments[nums[i]], i };
            }
            compliments[target-nums[i]] = i;
        }
        return { -1, -1 };
    }
};
