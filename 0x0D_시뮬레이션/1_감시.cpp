#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, m;
int board[10][10], course[10][10];
vector<pair<int, int>> cctv;

void cctv_course(int, int, int);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int min = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] != 0 && board[i][j] != 6) cctv.push_back({i, j});
            if(board[i][j] == 0) min++;
        }
    
    for(int tmp = 0; tmp < 1<<(2*cctv.size()); tmp++) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                course[i][j] = board[i][j];
        int tmp2 = tmp;
        for(int i = 0; i < cctv.size(); i++) {
            int dir = tmp2 % 4;
            tmp2 /= 4;
            int x, y; tie(x, y) = cctv[i];
            switch(board[x][y]) {
            case 1:
                cctv_course(x, y, dir);
                break;
            case 2:
                cctv_course(x, y, dir);
                cctv_course(x, y, dir+2);
                break;
            case 3:
                cctv_course(x, y, dir);
                cctv_course(x, y, dir+1);
                break;
            case 4:
                cctv_course(x, y, dir);
                cctv_course(x, y, dir+1);
                cctv_course(x, y, dir+2);
                break;
            case 5:
                cctv_course(x, y, dir);
                cctv_course(x, y, dir+1);
                cctv_course(x, y, dir+2);
                cctv_course(x, y, dir+3);
                break;            
            }
        }
        int val = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                val += (course[i][j]==0);
        if(val < min) min = val;
    }
    cout << min;
}
void cctv_course(int x, int y, int dir) {
    dir %= 4;
    while(1) {
        x += dx[dir];
        y += dy[dir];
        if(x < 0 || x >= n || y < 0 || y >= m || board[x][y] == 6) return;
        course[x][y] = -1;
    }
}

// https://www.acmicpc.net/problem/15683