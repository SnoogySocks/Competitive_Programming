/**
 * https://leetcode.com/problems/path-sum-iii/
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    const int mxN = 1000;
    int ans = 0;
    int sum = 0;
    unordered_map<long long, int> dp;
public:
    // Find the all possible sums with the current node
    void dfs (TreeNode* node, int targetSum) {
        if (!node) return;
        sum += node->val;
        if (dp[sum-targetSum]) {
            ans += dp[sum-targetSum];
        }
        ++dp[sum];
        dfs(node->left, targetSum);
        dfs(node->right, targetSum);

        --dp[sum-targetSum];
        sum -= node->val;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        dp[0] = 1;
        dfs(root, targetSum);
        return ans;
    }
};
