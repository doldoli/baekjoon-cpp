#include <iostream>
#include <cmath>

void solve_63() {
     std::ios_base::sync_with_stdio(false);
     std::cin.tie(NULL);

     int n{};
     std::cin >> n;
     int digits{1};
     for (int i = n; !(0 < i && i < 10);) {
          digits += 1;
          i /= 10;
     }

     int sum{};
     int gen{};
     for (int i = n - digits * 9; i <= n; ++i) {
          gen = i;
          sum = gen;
          for (int j = digits - 1, temp = gen; j >= 0; --j) { // 각 자릿수 덧셈
               sum += temp / (static_cast<int>(pow(10, j)));
               temp = temp % (static_cast<int>(pow(10, j)));
          }
          if (sum == n) break;
     }
     if (gen == n) std::cout << 0 << '\n';
     else std::cout << gen << '\n';
}

/*
학습

1. for 문 내부 변수 2개 가능
     - for(int i = 0, temp = 1; (); ++i, ++temp)

2. 각 자릿수를 더하는 로직
     - pow 함수x (느리고, 기본 return type이 double이기에, int의 경우 형변환도 해줘야하고 부동소수점 오류 가능성)
     - while 문과 % 모듈러 연산 쓰는 것이 간단하고 표준적

3. 개선 코드

while (temp > 0) { // 다 더하면 temp == 0 이 됨
     sum += temp % 10; // 1의 자릿수 더함
     temp /= 10; // 1의 자릿수 제거
}
*/