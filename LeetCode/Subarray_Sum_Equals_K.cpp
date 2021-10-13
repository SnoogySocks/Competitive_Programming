//  https://leetcode.com/problems/subarray-sum-equals-k/submissions/
// October 13 2021

class Solution {
public:
    int subarraySum (vector<int>& nums, int k) {
        int cnt, sum;
        cnt = sum = 0;
        unordered_map<int, int> sumFreq;
        sumFreq[0] = 1;
        for (int n: nums) {
            sum += n;
            if (sumFreq.count(sum-k)) {
                cnt += sumFreq[sum-k];
            }
            if (!sumFreq.count(sum)) {
                sumFreq[sum] = 0;
            }
            ++sumFreq[sum];
        }
        return cnt;
    }
};
