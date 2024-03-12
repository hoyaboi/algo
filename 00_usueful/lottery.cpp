#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));
    bool esc = true;
    int cnt = 1;
    while(esc) {
        int num;
        bool lot[46] = {0};

        cout << cnt << ". Choose the type of lottery\n";
        cout << "(1 : Pension Lottery / 2 : Lotto / 3 : Exit) -> ";
        cin >> num;

        switch(num) {
        case 1:
            cout << "\n\tPL : " << rand() % 5 + 1 << " / ";
            for(int i = 0; i < 6; i++)
                cout << rand() % 10 << " ";
            cout << "\n\n";
            break;
        case 2:
            for(int cnt = 0; cnt < 6;) {
                int k = (rand() % 45) + 1;
                if(!lot[k]) {
                    lot[k] = true;
                    cnt++;
                }
            }
            cout << "\n\tL : ";
            for(int i = 1; i <= 45; i++)
                if(lot[i]) cout << i << " ";
            cout << "\n\n";
            break;
        case 3:
            esc = false;
            break;
        default:
            cout << "Wrong number. Please choose again\n\n";
            break;
        }
        cnt++;
    }

}