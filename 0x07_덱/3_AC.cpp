#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, size;
    string com, arr;
    cin >> n;


    while(n--) {
        int countR = 0;
        deque<int> deq;
        bool isError = false;
        cin >> com >> size >> arr;

        for(char &c : arr)
            if(c == '[' || c == ']' || c == ',') c = ' ';
        stringstream ss(arr);
        int num;
        while(ss >> num) deq.push_back(num);

        for(char c : com) {
            if(c == 'R') countR++;
            else if(c == 'D') {
                if(!deq.empty()) {
                    if(countR % 2 == 0) deq.pop_front();
                    else deq.pop_back();
                }
                else {
                    cout << "error\n";
                    isError = true;
                    break;
                }
            }
        }

        if(!isError) {
            if(countR % 2 != 0) reverse(deq.begin(), deq.end());
            cout << "[";
            if(!deq.empty())
                for(int i = 0; i < deq.size(); i++) {
                    cout << deq[i];
                    if(i != deq.size() - 1) cout << ",";
                }
            cout << "]\n";
        }
    }
}

// https://www.acmicpc.net/problem/5430