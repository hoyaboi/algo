#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second 

int board[102][102];
bool vis1[102][102];
bool vis2[102][102];
queue<pair<int, int>> que;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int k;  // size

void BFS(int, int);
void unBFS(int, int);
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int count1 = 0, count2 = 0;
    cin >> k;
    for(int i = 0; i < k; i++) {
        string tmp; cin >> tmp;
        for(int j = 0; j < k; j++)
            switch(tmp[j]) {
            case 'R': board[i][j] = 1; break;
            case 'G': board[i][j] = 2; break;
            case 'B': board[i][j] = 3; break;
            }
    }

    for(int i = 0; i < k; i++)
        for(int j = 0; j < k; j++)
            if(!vis1[i][j]) {
                BFS(i, j); 
                count1++;
            }
    cout << count1 << " ";

    for(int i = 0; i < k; i++)
        for(int j = 0; j < k; j++)
            if(!vis2[i][j]) {
                unBFS(i, j); 
                count2++;
            }
    cout << count2;
}

void BFS(int n, int m) {
    vis1[n][m] = 1;
    que.push({n, m});
    while(!que.empty()) {
        pair<int, int> cur = que.front(); que.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= k || ny < 0 || ny >= k || vis1[nx][ny]) continue;
            if(board[nx][ny] != board[n][m]) continue;
            vis1[nx][ny] = 1;
            que.push({nx, ny});
        }
    }
}
void unBFS(int n, int m) {
    vis2[n][m] = 1;
    que.push({n, m});
    while(!que.empty()) {
        pair<int, int> cur = que.front(); que.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= k || ny < 0 || ny >= k || vis2[nx][ny]) continue;
            if((board[nx][ny] == 3 && board[n][m] != 3) || (board[nx][ny] != 3 && board[n][m] == 3)) continue;
            vis2[nx][ny] = 1;
            que.push({nx, ny});
        }
    }
}

// https://www.acmicpc.net/problem/10026