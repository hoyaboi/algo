#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int n, nxt[3];
char board[10][10];
bool escape = false;

void back(int, int);
bool isPos(vector<pii>);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];

    back(0, 0);
    if(escape) cout << "YES";
    else cout << "NO";
}
void back(int k, int start) {
    if(escape) return;
    if(k == 3) {
        vector<pii> cur;
        for(int i = 0; i < k; i++) {
            int x = nxt[i] / n;
            int y = nxt[i] % n;
            if(board[x][y] == 'S' || board[x][y] == 'T') return;
            cur.push_back({x, y});
        }
        if(isPos(cur)) escape = true;
        return;
    }
    for(int i = start; i < n*n; i++) {
        nxt[k] = i;
        back(k+1, i+1);
    }
}
bool isPos(vector<pii> cur) {
    queue<pii> que;
    char tmp[10][10];
    memcpy(tmp, board, sizeof(board));
    for(auto& p : cur) tmp[p.first][p.second] = 'O';
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) 
            if(tmp[i][j] == 'T') que.push({i, j});
    
    while(!que.empty()) {
        pii teacher = que.front(); que.pop();
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(auto& dir : directions) {
            int x = teacher.first, y = teacher.second;
            while(true) {
                x += dir[0];
                y += dir[1];
                if(x < 0 || x >= n || y < 0 || y >= n || tmp[x][y] == 'O') break;
                if(tmp[x][y] == 'S') return false;
            }
        }
    }
    return true;
}


// https://www.acmicpc.net/problem/18428