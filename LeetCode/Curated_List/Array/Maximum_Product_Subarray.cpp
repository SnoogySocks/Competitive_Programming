// https://leetcode.com/problems/maximum-product-subarray/
// 12/23/2021

class Solution {
public:
    const int dne = INT_MIN;
    
    int identity (int n) {
        return n==dne? 1:n;
    }
    
    // Should always find a negative before it goes out of range
    int productUntilNeg (vector<int>& nums, int i, int dir) {
        int product = 1;
        for (; nums[i]>0; i += dir) {
            product *= nums[i];
        }
        return product*nums[i];
    }
    
    int maxProduct(vector<int>& nums) {
//        // Split array on zeros
//        // Take product of array on the subarrays
//        nums.push_back(0);
//        int prev0, maxProduct, product;
//        prev0 = -1;
//        maxProduct = product = dne;
//        for (int i = 0; i<nums.size(); ++i) {
//            // Take product of array on the subarrays between 0s
//            if (nums[i]!=0) {
//                product = identity(product)*nums[i];
//            } else if (nums[i]==0) { 
//                // If prducts are negative then iterate from the left or right side
//                //      to find the first negative and divide out the range of the 
//                //      largest sized negative
//                if (identity(product)<0) {
//                    int leftProd = productUntilNeg(nums, prev0+1, 1);
//                    int rightProd = productUntilNeg(nums, i-1, -1);
//                    
//                    // If there is only 1 element in the interval and it's negative
//                    // then just assign the product to the max neg
//                    if (i-prev0==2) {
//                        product = max(leftProd, rightProd);
//                    } else {
//                        product /= max(leftProd, rightProd);
//                    }
//                }
//                // cout<<product<<'\n';
//                // There is no zero at the end.
//                if (i!=nums.size()-1) {
//                    maxProduct = max(maxProduct, 0);
//                }
//                maxProduct = max(maxProduct, product);
//                product = dne;
//                prev0 = i;
//            }
//        }        
//        return maxProduct;
      
      // Better solution :(
        int mn, mx;
        mn = mx = 1;
        int ans = nums[0];
        for (int n: nums) {
            int a[] {n, n*mn, n*mx};
            mn = *min_element(a, a+3);
            mx = *max_element(a, a+3);
            ans = max(ans, mx);
        }
        return ans;
    }
};
