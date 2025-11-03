#include <iostream>

void solve_60() {
    unsigned long long n{};
    std::cin >> n;
    std::cout << ((n*(n+1)*(2*n+1) / 6) - (3*n*(n+1) / 2) + 2*n) / 2 << '\n' << 3 << '\n';
}