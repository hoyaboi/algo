#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<char> str;
    string input;
    int com_num;
    char com;

    cin >> input;
    for(int i = 0; i < input.size(); i++) {
        str.push_back(input[i]);
    }
    list<char>::iterator it = str.end();
    cin >> com_num;
    for(int i = 0; i < com_num; i++) {
        cin >> com;
        switch (com) {
        case 'L':
            if(it == str.begin()) break;
            it--;
            break;
        case 'D':
            if(it == str.end()) break;
            it++;
            break;
        case 'B':
            if(it == str.begin()) break;
            str.erase(prev(it));            // 이전 노드로 접근하기 위해 std::prev() 함수 사용
            break;
        case 'P':
            char insert_char;
            cin >> insert_char;
            str.insert(it, insert_char);
            break;
        }
    }

    for(auto it : str) cout << it;
}

// https://www.acmicpc.net/problem/1406