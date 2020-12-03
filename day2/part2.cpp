#include <bits/stdc++.h>

using namespace std;

ifstream fin("puzzle.in");
ofstream fout("puzzle.out");

int main(){
    string x;
    int ans = 0;
    while (getline(fin, x)){
        int a = 0, b = 0, i = 0;
        while (x[i] >= '0' && x[i] <= '9'){
            a = a * 10 + x[i] - '0';
            ++i;
        }
        ++i; // trec peste '-'
        while (x[i] >= '0' && x[i] <= '9'){
            b = b * 10 + x[i] - '0';
            ++i;
        }
        ++i; // trec peste spatiu
        char ch = x[i];
        i += 3;
        if (((x[i + a - 1] == ch) || (x[i + b - 1] == ch)) && (x[i + b - 1] != x[i + a - 1])){
            ++ans;
        }
    }
    fout << ans;
    fin.close();
    fout.close();
}
