#include <iostream>
#include <vector>
#include <string>

void Print(const std::vector<std::string>& v, int n, int m) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
        std::cout << v[i][j];
        }
        std::cout << std::endl;
    }

}

void solve_65() {
    int n{}, m{};
    std::cin >> n >> m;
    std::cin.ignore(1, '\n');

/*
char 타입 벡터로 입력받기 (std::cin >> 은 개행(공백)아닌 문자를 만나면 저장)
    std::vector<char> width(n);
    std::vector<std::vector<char>> length(m);
    
    //vector에 문자열 입력받고 저장하자
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            char temp;
            std::cin >> temp;
            width.push_back(temp);
        }
        
        length.push_back(width);
    }
}
*/
    // m행 n열 문자열을 벡터형태로 저장하자.
    std::vector<std::string> lines;
    std::string temp_line;

    for (int i = 0; 
        i < n && std::getline(std::cin, temp_line); ++i) {
        lines.push_back(temp_line);
    }
    // 바꿔야되는 최솟값 저장
    int min_change = 65;
    
    // 각 후보점에 대해 알고리즘 반복
    // 일단 공통부분 keep 안하고 모든 후보점에 대해 찾는 알고리즘
    for (int i = 0; i < m - 7; ++i) { // 상하 후보점
        for (int j = 0; j < n - 7; ++j) { // 좌우 후보점
            // 점 찾는 알고리즘
            // 일단 공통부분 keep 안하고 일일이 다 검사
            // 시작점 lines[row][col]
            // 바꿔야하는 점의 개수
            int change_cnt = 0;
            char base = lines [i][j];
            // 시작점. 기준 문자
            for (int row = i; row < i + 8; ++row) {
                for (int col = j; col < j + 8; ++col) {

                    // 시작 행이랑 같은 패턴의 줄
                    if (row % 2 == i % 2) {
                        // 시작열이랑 같은 열의 문자가 기준문자와 같아야됨
                        if (col % 2 == j % 2) {
                            // 시작점이랑 같지 않으면 cnt += 1
                            change_cnt += (base == lines[row][col]) ? 0 : 1;
                        }
                        // 시작열이랑 다른 열의 문자. 기준문자와 달라야함
                        // 시작점이랑 같ec으면 cnt += 1
                        else change_cnt += (base == lines[row][col]) ? 1 : 0;
                    }
                    
                    // 시작 행이랑 반대 패턴의 줄
                    else {
                        // 시작열이랑 다른 패턴이어야 옳음
                        // 시작열이랑 같은 패턴의 열인 경우 -> 기준문자와 달라야 옳음
                        if (col % 2 == j % 2) {
                            change_cnt += (base == lines[row][col]) ? 1 : 0;
                        }
                        // 시작열이랑 다른 패턴의 열인 경우 -> 기준 문자와 같아야 옳음
                        else change_cnt += (base == lines[row][col]) ? 0 : 1;
                    }
                }
            }
            if (change_cnt >= 33) {
                change_cnt = 65 - change_cnt;
            }
            if (change_cnt < min_change) min_change = change_cnt;
        }
    }
    std::cout << min_change << '\n';
}
// 아 i > ~~ 이거 빼먹었다 ..