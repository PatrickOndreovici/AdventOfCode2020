#include <bits/stdc++.h>

using namespace std;

ifstream fin("puzzle.in");
ofstream fout("puzzle.out");

int main(){
    int x;
    vector <int> fr(2005);
    while (fin >> x){
        if (fr[2020 - x]){
            fout << x * (2020 - x);
            return 0;
        }
        fr[x] = 1;
    }
    fin.close();
    fout.close();
}
