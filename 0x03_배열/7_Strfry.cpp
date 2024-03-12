#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    while(n--) {
        string stmp, str;
        vector<int> count(26);
        bool isPossible = true;;

        cin >> stmp >> str;
        for(char s : stmp) count[s-'a']++;
        for(char s : str) count[s-'a']--;
        for(int i : count)
            if(i != 0) isPossible = false;

        if(isPossible) cout << "Possible\n";
        else cout << "Impossible\n";
    }
}

// https://www.acmicpc.net/problem/11328