# https://leetcode.com/problems/3sum/
# October 13 2021

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums)<3:
            return []
        nums.sort()
        
        ans = set()
        
        for i in range(len(nums)):
            left = i+1
            right = len(nums)-1
            while left<right:
                sum = nums[i]+nums[left]+nums[right]
                if sum<0:
                    left += 1
                elif sum>0:
                    right -= 1
                elif sum==0:
                    ans.add((nums[i], nums[left], nums[right]))
                    right -= 1
                  
        ans = list(ans)
        for i in range(len(ans)):
            ans[i] = list(ans[i])
        return ans
