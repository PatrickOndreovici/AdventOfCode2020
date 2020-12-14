#include <bits/stdc++.h>

using namespace std;

ifstream fin("puzzle.in");
ofstream fout("puzzle.out");

int main(){
    vector <long long> v;
    long long x;
    while (fin >> x){
        v.push_back(x);
    }
    for (int i = 25; i < v.size(); ++i){
        bool ok = false;
        for (int j = i - 25; j < i - 1 && !ok; ++j){
            for (int k = j + 1; k < i && !ok; ++k){
                if (v[j] + v[k] == v[i]){
                    ok = true;
                }
            }
        }
        if (ok == false){
            fout << v[i];
            return 0;
        }
    }
    fin.close();
    fout.close();
}
