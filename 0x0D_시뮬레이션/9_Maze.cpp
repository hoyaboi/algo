#include <bits/stdc++.h>
using namespace std;

bool board[6][6][6], tmp[6][6][6], maze[6][6][6];
int vis[6][6][6];
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void rotate(int, int);
void BFS(tuple<int, int, int>);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 5x5x5 board 입력
    for(int k = 0; k < 5; k++)
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
                cin >> board[k][i][j];

    // 보드 회전 결정(4진수)
    int min_path = INT_MAX;
    for(int i = 0; i < 1<<(2*5); i++) {
        int rot = i;
        for(int j = 0; j < 5; j++) {
            rotate(j, rot % 4);
            rot >>= 2;
        }
        // 쌓는 순서 결정
        int order[5] = {0, 1, 2, 3, 4};
        do {
            for(int p = 0; p < 5; p++)
                for(int q = 0; q < 5; q++)
                    for(int r = 0; r < 5; r++)
                        maze[p][q][r] = tmp[order[p]][q][r];
            // BFS 수행
            if(!maze[0][0][0] || !maze[4][4][4]) continue;
            BFS({0, 0, 0});
            if(vis[4][4][4]) min_path = min(min_path, vis[4][4][4]);
        } while(next_permutation(order, order + 5));
    }
    if(min_path != INT_MAX) cout << min_path - 1;
    else cout << -1;
}
void rotate(int which, int direction) {
    // board rotate 수행해서 tmp에 복사
    bool sub[6][6] = {};
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            tmp[which][i][j] = sub[i][j] = board[which][i][j];
    while(direction--) {
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++) {
                tmp[which][i][j] = sub[4-j][i];
            }
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < 5; j++)
                sub[i][j] = tmp[which][i][j];
    }
}
void BFS(tuple<int, int, int> start) {
    // maze BFS 수행
    for(int j = 0; j < 5; j++)
        for(int k = 0; k < 5; k++)
            fill(vis[j][k], vis[j][k] + 5, 0);
    queue<tuple<int, int, int>> que;
    vis[get<0>(start)][get<1>(start)][get<2>(start)] = 1;
    que.push(start);
    while(!que.empty()) {
        int curX, curY, curZ;
        tie(curX, curY, curZ) = que.front(); que.pop();
        for(int dir = 0; dir < 6; dir++) {
            int nx = curX + dx[dir];
            int ny = curY + dy[dir];
            int nz = curZ + dz[dir];
            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5) continue;
            if(vis[nz][nx][ny] || !maze[nz][nx][ny]) continue;
            vis[nz][nx][ny] = vis[curZ][curX][curY] + 1;
            que.push({nx, ny, nz});
        }
    }
}

// https://www.acmicpc.net/problem/16985