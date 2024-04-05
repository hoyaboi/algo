#include <bits/stdc++.h>
using namespace std;

long long d, x, y;
string n;

// 사분면 코드를 좌표로 변환
void toCoords(long long &x, long long &y, string n) {
    x = y = 0;
    long long len = 1LL << d; // 2^d, 격자 크기
    for (char c : n) {
        len >>= 1; // 현재 사분면의 크기
        if (c == '1') {
            y += len; // 상단 우측
        } else if (c == '2') {
            // 상단 좌측
        } else if (c == '3') {
            x += len; // 하단 좌측
        } else if (c == '4') {
            x += len; // 하단 우측
            y += len;
        }
    }
}

// 좌표를 사분면 코드로 변환
void toQuad(long long x, long long y, long long size, string &result) {
    if (size == 1) return;
    size /= 2;
    if (x < size && y < size) { // 상단 좌측
        result += '2';
        toQuad(x, y, size, result);
    } else if (x < size && y >= size) { // 상단 우측
        result += '1';
        toQuad(x, y - size, size, result);
    } else if (x >= size && y < size) { // 하단 좌측
        result += '3';
        toQuad(x - size, y, size, result);
    } else { // 하단 우측
        result += '4';
        toQuad(x - size, y - size, size, result);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> d >> n;
    cin >> x >> y;

    long long curX, curY;
    toCoords(curX, curY, n);

    // 이동 처리
    curX -= y;
    curY += x;

    // 좌표가 격자 범위를 벗어나는 경우 처리
    long long maxCoord = (1LL << d) - 1;
    if (curX < 0 || curX > maxCoord || curY < 0 || curY > maxCoord) {
        cout << -1 << '\n';
        return 0;
    }

    string result = "";
    toQuad(curX, curY, 1LL << d, result);
    cout << result << '\n';

    return 0;
}


// https://www.acmicpc.net/problem/1891