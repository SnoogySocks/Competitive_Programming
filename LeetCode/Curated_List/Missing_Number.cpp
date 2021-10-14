// https://leetcode.com/problems/missing-number/
// Ocotber 14 2021

class Solution {
public:
    // Function to return the XOR of elements
    // from the range [1, n]
    int findXOR(int n) {
        int mod = n % 4;

        // If n is a multiple of 4
        if (mod == 0)
            return n;

        // If n % 4 gives remainder 1
        else if (mod == 1)
            return 1;

        // If n % 4 gives remainder 2
        else if (mod == 2)
            return n + 1;

        // If n % 4 gives remainder 3
        else if (mod == 3)
            return 0;
        
        return -1;
    }
    int missingNumber(vector<int>& nums) {
        // int t = 0;
        // for (int i = 0; i<nums.size(); ++i) {
        //     t += nums[i];
        // }
        // return (nums.size()*(nums.size()+1)>>1)-t;
        int yes = findXOR(nums.size());
        for (const int& i: nums) {
            yes ^= i;
        }
        return yes;
    }
};
