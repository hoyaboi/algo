#include <bits/stdc++.h>
using namespace std;

void rotate(int, int);
deque<bool> gear[4];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 4; i++) {
        string tmp; cin >> tmp;
        for(char c : tmp) gear[i].push_back(c-'0');
    }
    int n; cin >> n;
    while(n--) {
        int num, dir; cin >> num >> dir;
        bool isSame[3] = {0};
        for(int i = 0; i < 3; i++)
            if(gear[i][2] == gear[i+1][6]) isSame[i] = true;
        int tmp1 = dir, tmp2 = dir;
        for(int i = num-2; i >= 0; i--) {
            if(isSame[i]) break;
            tmp1 *= (-1);
            rotate(i, tmp1);
        }
        rotate(num-1, dir);
        for(int i = num; i < 4; i++) {
            if(isSame[i-1]) break;
            tmp2 *= -1;
            rotate(i, tmp2);
        }
    }
    int sum = 0;
    for(int i = 0; i < 4; i++)
        sum += (gear[i][0] << i);
    cout << sum;
}
void rotate(int k, int dir) {
    if(dir == 1) {
        bool tmp = gear[k].back();
        gear[k].pop_back();
        gear[k].push_front(tmp);
    }
    else {
        bool tmp = gear[k].front();
        gear[k].pop_front();
        gear[k].push_back(tmp);
    }
}

// https://www.acmicpc.net/problem/14891