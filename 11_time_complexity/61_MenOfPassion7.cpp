#include <iostream>
bool IsSatisfied(const int& a1, const int& a2, const int& c, const int& n0) {
    if (c-a1 > 0) {
        if (a2/(c-a1) <= n0) {
            return true;
        }
        else return false;
    }
    else if (c-a1 == 0) {
        if (a2 <= 0) {
            return true;
        }
        else return false;
    }
    else {
        return false;
    }
}
void solve_61() {
    int a1{}, a2{}, c{}, n0{};
    std::cin >> a1 >> a2 >> c >> n0;
    if (IsSatisfied(a1, a2, c, n0)) {
        std::cout << 1 << '\n';
    }
    else {
        std::cout << 0 << '\n';
    }
}

/*
학습
1. 수학적 연산시에 int, unsigned int 처럼 다른 타입이 오면 묵시적 형변환이 일어나, 원하는 결과가 나올 수도 있음.
따라서 이런 경우 (형변환을 해주거나) 애초에 자료형을 통일해주는 것이 권장됨

2. non-void function에 대해 if - else if - else if로 끝나면 수학적으로는 완벽해도, 
컴파일러는 구조만 검사하기에 세개가 모두 false인경우 return 이 없으면 경고 발생시킴
따라서 수학적으로 맞더라도 if - else if -else 로 닫아줘야 함
*/