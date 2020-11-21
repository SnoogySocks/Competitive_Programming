// 06/2020

#include <iostream>
#include <forward_list>

#define ll long long

const int mxN = 10;

int gcf (int a, int b) {

    while (a != 0) {
        int temp = a;
        a = b % a;
        b = temp;
    }
    return b;

}

int get_lcm (int a, int b) {
    return (a * b) / gcf(a, b);
}

void solution() {

    int m, n;
    std::cin >> m >> n;

    int a[mxN], b[mxN];
    for (int i = 0; i < m; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    int lcm = a[0];
    int lowest = 0;
    for (int i = 1; i < m || i < n; i++) {
        if (i < m) {
            lcm = get_lcm(a[i], lcm);
        }
        if (i < n) {
            lowest = (b[i] < b[lowest]) ? i : lowest;
        }
    }
    int temp = b[0];
    b[0] = b[lowest];
    b[lowest] = temp;

    std::forward_list<int> nums_btwn;
    int n_ns_btwn = 0;

    for (int i = lcm; i <= b[0]; i += lcm) {
        if (b[0] % i == 0) {
            nums_btwn.push_front(i);
            n_ns_btwn++;
        }
    }

    for (int i = 1; i < n; i++) {
        for (auto it = nums_btwn.before_begin(); it != nums_btwn.end();) {

            auto next_it = std::next(it);
            if (next_it != nums_btwn.end() && b[i] % *next_it != 0) {
                nums_btwn.erase_after(it);
                n_ns_btwn--;
            } else {
                it++;
            }

        }
    }
    std::cout << n_ns_btwn;

}

int main() {

    solution();
    std::cout << '\n';

    return 0;
}
