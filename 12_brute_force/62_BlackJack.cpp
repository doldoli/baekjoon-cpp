// 문제: N장의 카드에 써져 있는 숫자가 주어졌을 때, M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합을 구해 출력하시오.
// 입력: 첫째 줄에 카드의 개수 N(3 ≤ N ≤ 100)과 M(10 ≤ M ≤ 300,000)이 주어진다. 둘째 줄에는 카드에 쓰여 있는 수가 주어지며, 이 값은 100,000을 넘지 않는 양의 정수이다. 합이 M을 넘지 않는 카드 3장을 찾을 수 있는 경우만 입력으로 주어진다.

#include <iostream>
#include <vector>

void solve_62() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n{}, m{};
    std::cin >> n >> m;

    std::vector<int> cards(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> cards[i];
    }
    
    int best_sum = 0;
    bool found_exact = false;

    for (int i = 0; i < n - 2; ++i) {
        if (found_exact) break;

        for (int j = i+1; j < n-1; ++j) {
            if (found_exact) break;

            for (int k = j+1; k < n; ++k) {

                int cur_sum = cards[i] + cards[j] + cards[k];

                if (cur_sum == m) {
                    best_sum = m;
                    found_exact = true;
                    break;
                }
                
                if (cur_sum < m && cur_sum > best_sum) {
                    best_sum = cur_sum;
                }
            }
        }
    }
    std::cout << best_sum << '\n';
}

/*
학습
1. 동적 배열 선언
    - 컴파일 시점이 아니라 실행 시점에 n(배열의 크기)이 결정되기에 동적 배열 선언해야함
    - std::vector -> 동적 배열
    - unsinged int* cards = new unsinged int[n]; -> 동적 배열 선언
        - new 로 할당한 메모리는 사용 후 delete 연산자로 메모리 해제해야 함
        - delete[] cards; (cards이 배열이기에 delete [], 단일 객체면 delete)
        - new ~의 결과는 할당된 메모리의 주소이기에 포인터로 이 주소 값을 저장해야 함
        - delete로 수동 관리하는 게 힘들기 때문에 std::vector 사용 권장
2. - 연산 시 주의점
    - unsinged int의 사용을 주의하자. 결과값이 음수인 경우 unsinged int로 결과를 저장하면 언더플로우 발생
    - 차이값을 비교하고 싶을 떄는 반드시 절댓값 써주기 !!!!!!!
3. if, else문 내부에서 변수 선언 (scope) / 변수 선언시 scope 주의
    - 만약 if, else 문 블록 내부에서 변수를 선언하면 지역 변수로 취급되기에 scope 주의!
    - 밖에서 선언하고 값만 바꾸던가 아니면 삼항 연산자 (int diff = (m-sum < 0) ? 300000 : (m-sum);) 이용
*/

/*
개선점
1. diff 대신 best_sum으로 로직 단순화
2. 초기 cards[0] + cards[1] + cards[2] 한번더 계산해도 되니 구조적으로 통일성 주는 게 더 나음
*/