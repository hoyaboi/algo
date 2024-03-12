#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second 

int n, m, chicken_sum = INT_MAX;
int board[50][50];
vector<pair<int, int>> chicken, house, sel;

void func(int, int);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) house.push_back({i, j});
            else if(board[i][j] == 2) chicken.push_back({i, j});
        }
    func(0, 0);
    cout << chicken_sum;
}
void func(int k, int start) {
    if(k == m) {
        int sum = 0;
        for(auto h : house) {
            int dist = INT_MAX;
            for(auto s : sel) {
                int tmp = abs(h.X - s.X) + abs(h.Y - s.Y);
                dist = min(dist, tmp);
            }
            sum += dist;
        }
        chicken_sum = min(chicken_sum, sum);
        return;
    }
    for(int i = start; i < chicken.size(); i++) {
        sel.push_back(chicken[i]);
        func(k+1, i+1);
        sel.pop_back();
    }
}

// https://www.acmicpc.net/problem/15686