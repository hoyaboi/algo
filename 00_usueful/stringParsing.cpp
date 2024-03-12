#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str = "hello my name is hoyaboi";
    stringstream ss(str);
    vector<string> words;
    string word;

    while(getline(ss, word, ' '))
        words.push_back(word);
    
    for(string tmp : words) cout << "\"" << tmp << "\" ";
    // "hello" "my" "name" "is" "hoyaboi"
}