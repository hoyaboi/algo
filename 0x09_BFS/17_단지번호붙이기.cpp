#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second 

bool board[26][26];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        string tmp; cin >> tmp;
        for(int j = 0; j < n; j++)
            board[i][j] = tmp[j] - '0';
    }
    queue<pair<int, int>> que;
    vector<int> arr;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j]) {
                int cnt = 1;
                que.push({i, j});
                board[i][j] = 0;
                while(!que.empty()) {
                    pair<int, int> cur = que.front(); que.pop();
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(!board[nx][ny]) continue;
                        board[nx][ny] = 0;
                        que.push({nx, ny});
                        cnt++;
                    }
                }
                arr.push_back(cnt);
            }
        }
    }
    sort(arr.begin(), arr.end());
    cout << arr.size() << "\n";
    for(int i : arr) cout << i << "\n";
}

// https://www.acmicpc.net/problem/2667