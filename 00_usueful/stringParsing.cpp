#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* ------------------------- parsing 1 ------------------------- */

    string str = "hello my name is hoyaboi";
    stringstream ss(str);
    vector<string> words;
    string word;

    while(getline(ss, word, ' '))
        words.push_back(word);
    
    for(string tmp : words) cout << "\"" << tmp << "\" ";
    // "hello" "my" "name" "is" "hoyaboi"


    /* ------------------------- parsing 2 ------------------------- */

    string str2 = "11 22 33 44 55";
    stringstream ss2(str2);
    vector<int> vec;
    int num;

    while(ss2 >> num) vec.push_back(num);

    for(int i : vec) cout << i << " ";
    // 11 22 33 44 55

}

