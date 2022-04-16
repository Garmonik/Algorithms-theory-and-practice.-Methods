#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

typedef struct{
    int freq;
    string letter;
} LETTER_TO_FREQ;

int main(){
    auto comp = [] (LETTER_TO_FREQ a, LETTER_TO_FREQ b) {return (b.freq == a.freq) ? a.letter > b.letter : a.freq > b.freq; };
    set<LETTER_TO_FREQ, decltype(comp)> set_l(comp);
    priority_queue<LETTER_TO_FREQ, vector<LETTER_TO_FREQ>, decltype(comp)> pr_q(comp);
    map<char, string> coder;
    LETTER_TO_FREQ curLetter1;
    LETTER_TO_FREQ curLetter2;
    string input;
    cin >> input;
    for(char c: input){
        string s;
        s += c;
        int amount = count(input.begin(), input.end(), c);
        set_l.insert({amount, s});
    }

    for(auto s: set_l)
        pr_q.push(s);

    if(pr_q.size() == 1)
        coder[pr_q.top().letter[0]] = '0';

    while(pr_q.size() != 1){
        curLetter1 = pr_q.top();
        for (auto ch: curLetter1.letter)
            coder[ch] = '0' + coder[ch];
        pr_q.pop();
        curLetter2 = pr_q.top();
        for (auto ch: curLetter2.letter)
            coder[ch] = '1' + coder[ch];
        pr_q.pop();
        pr_q.push({curLetter1.freq + curLetter2.freq, curLetter1.letter + curLetter2.letter});
    }

    string result;
    for(char c: input){
        result += coder[c];
    }

    cout << coder.size() << " " << result.size() << endl;

    for(auto a: coder){
        cout << a.first << ": " << a.second << endl;
    }

    cout << result << endl;
    return 0;
}
