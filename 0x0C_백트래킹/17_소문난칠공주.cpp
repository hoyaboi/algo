#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second

int cur[7], cnt;
bool board[6][6], team[6][6];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void func(int, int);
bool BFS();
bool checkS();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 5; i++) {
        string tmp; cin >> tmp;
        for(int j = 0; j < 5; j++)
            if(tmp[j] == 'S') board[i][j] = 1;
    }

    // 7개의 좌표를 조합으로 뽑음
    func(0, 0);
    cout << cnt;
    // 7개의 좌표를 team 1로 두고 BFS 시행을 통해 몇 개의 덩이인지 확인
    // if 1개 덩이 & 1(S파)가 4개 이상이면 cnt 증가
}
void func(int k, int start) {
    if(k == 7) {
        for(int i = 0; i < 5; i++) fill(team[i], team[i] + 5, 0);
        for(int i = 0; i < 7; i++) team[cur[i]/5][cur[i]%5] = 1;
        if(BFS() && checkS()) cnt++;
        return;
    }
    for(int i = start; i < 25; i++) {
        cur[k] = i;
        func(k+1, i+1);
    }
}
bool BFS() {
    int group = 0;
    int tmp[6][6];
    for(int p = 0; p < 5; p++)
        for(int q = 0; q < 5; q++)
            tmp[p][q] = team[p][q];
    queue<pair<int, int>> que;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(tmp[i][j]) {
                group++;
                que.push({i, j});
                tmp[i][j] = 0;
                while(!que.empty()) {
                    pair<int, int> cur = que.front(); que.pop();
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
                        if(!tmp[nx][ny]) continue;
                        tmp[nx][ny] = 0;
                        que.push({nx, ny});
                    }
                }
            }
        }
    }
    return group == 1 ? 1 : 0;
}
bool checkS() {
    int cntS = 0;
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            if(board[i][j] && team[i][j]) cntS++;
    return cntS >= 4 ? 1 : 0;
}

// https://www.acmicpc.net/problem/1941