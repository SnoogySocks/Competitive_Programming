// https://dmoj.ca/problem/avatarearth
// 12/2020

#include <bits/stdc++.h>

using namespace std;

int main() {
    int x,y,x1,y1,x2,y2;
    cin>>x>>y>>x1>>y1>>x2>>y2;
    puts((x1<x&&x<x2&&y1<y&&y<y2)?"Yes":"No");
    
    return 0;
}
