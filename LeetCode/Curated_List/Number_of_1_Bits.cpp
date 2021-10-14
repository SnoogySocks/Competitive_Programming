// https://leetcode.com/problems/number-of-1-bits/submissions/
// 14 October 2021

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n!=0) {
            n -= n&-n;
            ++cnt;
        }
        return cnt;
    }
};
