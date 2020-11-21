// 08/2020
// https://www.hackerrank.com/challenges/angry-professor/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        int m=0;
        cin >> n >> k;
        vector<int> a(n);
        for(int a_i = 0;a_i < n;a_i++){
           cin >> a[a_i];
            if(a[a_i]<=0)
                m++;
        }
        if(m>=k)
            cout<<"NO"<<'\n';
        else
            cout<<"YES"<<'\n';
        
    }
    return 0;
}
