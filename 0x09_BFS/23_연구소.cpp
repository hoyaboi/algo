#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second 
typedef pair<int, int> pii;

int board[10][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m; cin >> n >> m;
    queue<pii> que;
    vector<pii> empty;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2) que.push({i, j});
            else if(board[i][j] == 0) empty.push_back({i, j});
        }
    
    vector<vector<pii>> walls;
    vector<int> comb(empty.size(), 0);
    fill(comb.end()-3, comb.end(), 1);

    do {
        vector<pii> tempWall;
        for (int i = 0; i < comb.size(); i++) {
            if (comb[i] == 1) tempWall.push_back(empty[i]);
        }
        walls.push_back(tempWall);
    } while (next_permutation(comb.begin(), comb.end()));

    int ans = 0;
    for(auto &wall : walls) {
        bool nxt = 0;
        queue<pii> qtmp = que;
        int tmp[10][10];
        for(int j = 0; j < n; j++)
            for(int k = 0; k < m; k++)
                tmp[j][k] = board[j][k];

        for(int j = 0; j < 3; j++) {
            int wx = wall[j].X;
            int wy = wall[j].Y;
            if(board[wx][wy] == 1 || board[wx][wy] == 2) {
                nxt = 1;
                break;
            }
            tmp[wx][wy] = 1;
        }

        while(!qtmp.empty()) {
            pii cur = qtmp.front(); qtmp.pop();
            for(int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || tmp[nx][ny]) continue;
                tmp[nx][ny] = 2;
                qtmp.push({nx, ny});
            }
        }

        int cnt = 0;
        for(int p = 0; p < n; p++)
            for(int q = 0; q < m; q++)
                if(tmp[p][q] == 0) cnt++;

        ans = max(ans, cnt);
    }

    cout << ans;
}

// https://www.acmicpc.net/problem/14502

