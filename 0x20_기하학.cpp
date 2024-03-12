#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pii;

int CCW(pii, pii, pii);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // CCW 함수 : 세 점 p1, p2, p3를 순서대로 이은 선분이 반시계면 1, 시계면 -1, 일직선이면 0 return
    pii p1 = {0, 0};
    pii p2 = {2, 1};
    pii p3 = {1, 4};
    cout << CCW(p1, p2, p3) << "\n";

    // 컨벡스 헐 알고리즘 : 볼록한 껍질을 만드는 알고리즘
    // https://levenshtein.tistory.com/178
    // 0x20_기하학 1_컨벡스헐.cpp 참고
}

int CCW(pii p1, pii p2, pii p3) {
    int ccw = (p2.X-p1.X)*(p3.Y-p2.Y)-(p3.X-p2.X)*(p2.Y-p1.Y);
    if(ccw > 0) return 1;
    else if(ccw < 0) return -1;
    return 0;
}