#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define MAX 40000
typedef long long ll;
typedef pair<ll, ll> pii;

pii start = {MAX, MAX};
stack<pii> edge;
int n; 

int CCW(pii, pii, pii);
void convexhull(vector<pii>);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<pii> point(n);
    for(auto& a : point) {
        cin >> a.X >> a.Y;
        if(start.Y < a.Y) continue;
        if(start.Y > a.Y) start = {a.X, a.Y};
        else if(start.X > a.X) start.X = a.X;
    }

    sort(point.begin(), point.end(), [](pii p1, pii p2) {
        int ccw = CCW(start, p1, p2);
        if (ccw) return ccw > 0;
        if (p1.Y != p2.Y) return p1.Y < p2.Y;
        return p1.X < p2.X;
    });

    convexhull(point);
    cout << edge.size();
}
int CCW(pii p1, pii p2, pii p3) {
    ll CCW = (p2.X-p1.X)*(p3.Y-p2.Y)-(p3.X-p2.X)*(p2.Y-p1.Y);
    if(CCW > 0) return 1;
    else if(CCW < 0) return -1;
    else return 0;
}
void convexhull(vector<pii> points) {
    for (int i = 0; i < n; ++i) {
        while (edge.size() >= 2) {
            pii second = edge.top();
            edge.pop();
            pii first = edge.top();
            if (CCW(first, second, points[i]) > 0) {
                edge.push(second);
                break;
            }
        }
        edge.push(points[i]);
    }
}

// https://www.acmicpc.net/problem/1708