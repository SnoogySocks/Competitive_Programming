// https://leetcode.com/problems/container-with-most-water/submissions/
// 13 October 2021

class Solution {
public:
    
    struct Container {
        vector<int> heights;
        int left, right;
        Container (vector<int>& heights) 
            : left(0), right(heights.size()-1), heights(heights) {}
        Container (vector<int>& heights, int left, int right) 
            : left(left), right(right), heights(heights) {}
        
        void update (int left, int right) {
            this->left = left;
            this->right = right;
        }
        void update (const Container& c) {
            update(c.left, c.right);
        }
        
        bool shorterIsLeft () {
            return heights[left]<heights[right];
        }
        
        int getWidth () {
            return right-left;
        }
        
        int getHeight () {
            return min(heights[left], heights[right]);
        }
        
        int getArea () {
            return getWidth()*getHeight();
        }
        
        void maxCont (Container& c) {
            if (getArea()<c.getArea()) {
                update(c);
            }
        }
        
        void print () {
            cout<<left<<' '<<right<<'\n';
        }
    };
    
    int maxArea (vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        Container maxCont(height);
        Container curCont(height);
        
        while (left<right) {
            if (curCont.shorterIsLeft() && height[curCont.left]<height[++left]) {
                curCont.left = left;
                maxCont.maxCont(curCont);
            } else if (!curCont.shorterIsLeft() && height[curCont.right]<height[--right]) {
                curCont.right = right;
                maxCont.maxCont(curCont);
            }
        }
        
        return maxCont.getArea();
    }
};
// [2,3,4,5,18,17,6]
// [5,2,12,1,5,3,4,11,9,4]
/*
2 3 1 3 2
*/
