// 08/2020
// https://www.hackerrank.com/challenges/the-time-in-words/problem

#include <bits/stdc++.h>

using namespace std;

char numbers[31][19] = {
    "o' clock", 
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "quarter",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
    "twenty",
    "twenty one",
    "twenty two",
    "twenty three",
    "twenty four",
    "twenty five",
    "twenty six",
    "twenty seven",
    "twenty eight",
    "twenty nine",
    "half"
};

int main() {

    int h, m;
    scanf("%d%d", &h, &m);

    bool is_past = m<=30;
    int n = 30-m%30;
    if (m==0) {
        printf("%s o' clock", numbers[h]);
    } else if (m==1||m==59) {
        printf("one minute %s %s", (is_past)?"past":"to", numbers[is_past?h:h+1]);
    } else if (m==15||m==30||n==15) {
        printf("%s %s %s", numbers[(is_past)?m:n], (is_past)?"past":"to", numbers[is_past?h:h+1]);
    }
    else if (is_past) {
        printf("%s minutes past %s", numbers[m], numbers[h]);
    } else {
        printf("%s minutes to %s", numbers[n], numbers[h+1]);
    }

    return 0;
    
}
