// https://www.hackerrank.com/challenges/insertion-sort/problem
// 02/2021

#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5;
vector<int> leftTemp(mxN), rightTemp(mxN), arr(mxN);
long long cnt;

void merge (int left, int mid, int right) {
    
    int leftLen, rightLen;
    leftLen = mid-left+1;
    rightLen = right-mid;
    
    copy(arr.begin()+left, arr.begin()+mid+1, leftTemp.begin());
    copy(arr.begin()+mid+1, arr.begin()+right+1, rightTemp.begin());
    
    int l, r, pnt;
    l = r = 0;
    for (pnt = left; l<leftLen&&r<rightLen; ++pnt) {
        if (leftTemp[l]<=rightTemp[r]) {
            arr[pnt] = leftTemp[l++];
        } else {
            arr[pnt] = rightTemp[r++];
            cnt += leftLen-l;
        }
    }
    
    while (l<leftLen) arr[pnt++] = leftTemp[l++];
    while (r<rightLen) arr[pnt++] = rightTemp[r++];
    
}

void mergeSort (int len) {
    
    for (int curLen = 1; curLen<len; curLen *= 2) {
        for (int leftStart = 0; leftStart+curLen<len; leftStart += 2*curLen) {
            int mid, rightEnd;
            mid = leftStart+curLen-1;
            rightEnd = min(leftStart+2*curLen-1, len-1);
            merge(leftStart, mid, rightEnd);
        }
    }
    
}

int main() {
    
    int t, n; cin>>t;
    while (t--) {
        
        cin>>n;
        for (int i = 0; i<n; ++i) {
            cin>>arr[i];
        }
        cnt = 0;
        mergeSort(n);
        cout<<cnt<<'\n';
        
    }
    
}
