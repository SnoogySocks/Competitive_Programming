// https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/
// 23/12/2021

class Solution {
public:
   pair<int, int> getBounds (vector<int>& nums) {
       int l, r, m;
       l = 0;
       r = nums.size()-1;
       while (l<r && nums[l]>nums[r]) {
           m = l+(r-l)/2;
           if (nums[m]<nums[l]) {
               r = m;
           } else if (nums[r]<=nums[m]) {
               l = m+1;
           }
       }
       if (l==0) {
           return make_pair(0, nums.size()-1);
       } else {
           return make_pair(l, l-1);
       }
   }
   
   int getMidOfCycle (int l, int r, int n, int pivot) { 
       l = (l+pivot)%n;
       r = (r+pivot)%n;
       return (n+(l+(r-l)/2-pivot)%n)%n;
   }
   
   int search(vector<int>& nums, int target) {
       auto[l, r] = getBounds(nums);
       int pivot = nums.size()-l;
       while (l!=r) {
           int m = getMidOfCycle(l, r, nums.size(), pivot);
           if (nums[m]==target) {
               return m;
           } else if (nums[m]<target) {
               l = (m+1)%nums.size();
           } else if (nums[m]>target) {
               r = m;
           }
       }
       return nums[l]==target?l:-1;
   }
    
    // Better solution :(
//     int search (vector<int>& nums, int target) {
//         int l = 0;
//         int r = nums.size()-1;
//         while (l<=r) {
//             int m = l+(r-l)/2;
            
//             if (nums[m]==target) {
//                 return m;
//             // If right of m is sorted
//             } else if (nums[m]<=nums[r]) {
                
//                 // If in the range of right half, go there
//                 if (nums[m]<target && target<=nums[r]) {
//                     l = m+1;
//                 } else {
//                     r = m-1;
//                 }
                
//             // If left of m is sorted
//             } else if (nums[m]>=nums[l]) {
                
//                 // If in the range of left half, go there
//                 if (nums[l]<=target && target<nums[m]) {
//                     r = m-1;
//                 } else {
//                     l = m+1;
//                 }
                
//             }
//         }
//         return -1;
//     }   
};
