#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int, int, int> ti;

int n, minCost = INT_MAX;
int mp, mf, ms, mv;
vector<int> minWhich, which;
vector<ti> groc;

void back(int start) {
    int sumP = 0, sumF = 0, sumS = 0, sumV = 0, sumCost = 0;
    for (int idx : which) {
        int tmpP, tmpF, tmpS, tmpV, tmpC;
        tie(tmpP, tmpF, tmpS, tmpV, tmpC) = groc[idx];
        sumP += tmpP;
        sumF += tmpF;
        sumS += tmpS;
        sumV += tmpV;
        sumCost += tmpC;
    }

    if (sumP >= mp && sumF >= mf && sumS >= ms && sumV >= mv) {
        if (minCost > sumCost) {
            minCost = sumCost;
            minWhich = which;
        } else if (minCost == sumCost && lexicographical_compare(which.begin(), which.end(), minWhich.begin(), minWhich.end())) {
            minWhich = which;
        }
    }

    for (int i = start; i < n; i++) {
        which.push_back(i);
        back(i + 1);
        which.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < n; i++) {
        int p, f, s, v, cost;
        cin >> p >> f >> s >> v >> cost;
        groc.push_back({p, f, s, v, cost});
    }

    back(0);

    if (minCost == INT_MAX) {
        cout << -1;
        return 0;
    }
    cout << minCost << "\n";
    for (int i : minWhich) cout << i + 1 << " ";
    cout << "\n";

    return 0;
}


// https://www.acmicpc.net/problem/19942