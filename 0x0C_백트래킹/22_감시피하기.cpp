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
    if(k == 3) {
        vector<pii> cur;
        for(int i = 0; i < k; i++) {
            int x = nxt[i] / n;
            int y = nxt[i] % n;
            cur.push_back({x, y});
            if(isPos(cur)) escape = true;
            return;
        }
    }
    for(int i = start; i < n*n; i++) {
        nxt[k] = i;
        back(k+1, i+1);
    }
}
bool isPos(vector<pii> cur) {
    queue<pii> que;
    char tmp[10][10];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            tmp[i][j] = board[i][j];
            for(int k = 0; k < cur.size(); k++) {
                int x, y; tie(x, y) = cur[k];
                if(i == x && j == y) tmp[i][j] = 'O';
            }
            if(tmp[i][j] == 'S') que.push({i, j});
        }
    bool pos = true;
    while(!que.empty()) {
        if(!pos) break;
        pii std = que.front(); que.pop();
        for(int i = std.first-1; i >= 0; i--) {
            if(tmp[i][std.second] == 'O') break;
            if(tmp[i][std.second] == 'T') pos = false;
        }
        for(int i = std.first+1; i < n; i++) {
            if(tmp[i][std.second] == 'O') break;
            if(tmp[i][std.second] == 'T') pos = false;
        }
        for(int i = std.second-1; i >= 0; i--) {
            if(tmp[std.first][i] == 'O') break;
            if(tmp[std.first][i] == 'T') pos = false;
        }
        for(int i = std.second+1; i < n; i++) {
            if(tmp[std.first][i] == 'O') break;
            if(tmp[std.first][i] == 'T') pos = false;
        }
    }
    return pos;
}

// https://www.acmicpc.net/problem/18428