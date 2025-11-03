#include <iostream>

/*
for i -> 1 to n-1
    for j -> i + 1 to n

i = 1
    j -> 2 ~ n-1: n-1 times
i = 2
    j -> 3 ~ n-1: n-2 times
i = 3
    j -> 4 ~ n-1: n-3 times
...
i = n-2
    j -> n-1 ~ n: 2 times
i = n-1 
    j -> n ~ n: 1 times

O() -> sigma k (k=1 ~ n-1)
*/

void solve_58() {
    unsigned long long n{};
    std::cin >> n;
    std::cout << ((n-1) * n) / 2 << '\n' << 2 << '\n';
}