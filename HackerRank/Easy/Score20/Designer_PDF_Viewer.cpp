// 08/2020
// https://www.hackerrank.com/challenges/designer-pdf-viewer/problem

#include <bits/stdc++.h>

using namespace std;

int main() {

    int h[26];
    for (int i = 0; i < 26; i++) {
        scanf("%d", &h[i]);
    }

    int max = 0;
    int i = 0;
    getchar();
    for (int input = getchar(); input != -1; input = getchar(), i++) {
        int height = h[input-'a'];
        if (max < height) max = height;
    }
    printf("%d", max * i);

    return 0;
    
}
