// https://leetcode.com/problems/product-of-array-except-self/
// 12 October 2021

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        bool hasZeros = false;
        for (int i = 0; i<nums.size(); ++i) {
            if (nums[i]==0 && !hasZeros) {
                hasZeros = true;
                continue;
            }
            product = product*nums[i];
        }
        for (int i = 0; i<nums.size(); ++i) {
            if (!hasZeros) {
                nums[i] = product/nums[i];
            } else if (nums[i]==0) {
                nums[i] = product;
            } else {
                nums[i] = 0;
            }
        }
        return nums;
    }
};
