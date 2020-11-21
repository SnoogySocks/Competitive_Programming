// 08/2020
// https://www.hackerrank.com/challenges/reduced-string/problem

#include <bits/stdc++.h>

using namespace std;

const int mxN = 101;

int main() {

    char s[mxN]{};
    scanf("%s", s);
    int size = strlen(s);
    char stack[mxN];
    int top = -1;
    stack[0] = '\0';
    for (int i = 0; i<size; i++) {
        if (top==-1||stack[top]!=s[i]) {
            stack[++top] = s[i];
        } else top--;
    }
    if (top==-1) {
        puts("Empty String");
    } else {
        stack[top+1] = '\0';
        puts(stack);
    }

    return 0;
    
}
