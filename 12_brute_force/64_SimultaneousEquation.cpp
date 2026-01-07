#include <iostream>

void solve_64() {
    int a, b, c, d, e, f;
    std:: cin >> a >> b >> c >> d >> e >> f;

    int x{}, y{};

    if (a == 0) {
        y = c/b;
        x = (f - e*y) / d;
    }
    else if (b == 0) {
        x = c/a;
        y = (f-d*x) / e;
    }
    else if (d == 0) {
        y = f/e;
        x = (c-b*y) / a;
    }
    else if (e == 0) {
        x = f / d;
        y = (c-a*x) / b;
    }
    else {
        y = (c*d - a*f) / (b*d - a*e);
        x = (f - e*y) / d;
    }
    std::cout << x << ' ' << y << '\n';
}
// dx + (bd/a) y = (cd/a)
// dx + ey = f

// (bd - ae / a) y = (cd - af / a )
// y = cd - af / bd - ae
// x = (f - cy) / d

/*
연립 방정식 -> 행렬방정식 -> 크래머 공식으로 분기 줄이기

1. 크래머 공식
    - Ax = b
    - x_i = det(A_i) / det(A)
    - A_i 는 A의 i번째 열을 상수벡터 b로 치환한 행렬
*/
