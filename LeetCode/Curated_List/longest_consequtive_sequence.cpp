// https://leetcode.com/problems/longest-consecutive-sequence/solution/
// October 13, 2022

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set_nums(nums.begin(), nums.end());

        // num, size of sequence
        unordered_map<int, int*> visited; visited.reserve(nums.size());

        int longest_sequence = 0;
        for (int i = 0; i<nums.size(); ++i) {
            if (visited.count(nums[i])) continue;
            visited[nums[i]] = new int(1);

            for (int cur = nums[i]+1; set_nums.count(cur); ++cur) {
                // If already visited before, then link the sequences
                if (visited.count(cur)) {
                    *visited[nums[i]] += *visited[cur];
                    break;
                }
                ++*visited[nums[i]];
                visited[cur] = visited[nums[i]];
            }
            longest_sequence = max(longest_sequence, *visited[nums[i]]);
        }

        return longest_sequence;
    }
};
