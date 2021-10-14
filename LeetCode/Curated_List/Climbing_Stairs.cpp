// https://leetcode.com/problems/climbing-stairs/submissions/
// October 14 2021

class Solution {
public:
    int climbStairs(int n) {
        int a, b, cur;
        cur = a = b = 1;
        for (int i = 2; i<=n; ++i) {
            cur = a+b;
            a = b;
            b = cur;
        }
        return cur;
    }
};
