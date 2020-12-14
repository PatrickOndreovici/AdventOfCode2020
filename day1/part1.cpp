#include <bits/stdc++.h>

using namespace std;

ifstream fin("puzzle.in");
ofstream fout("puzzle.out");

int main(){
    int x;
    vector <int> v;
    while (fin >> x){
        v.push_back(x);
    }
    for (int i = 0; i < v.size(); ++i){
        for (int j = i + 1; j < v.size(); ++j){
            for (int k = j + 1; k < v.size(); ++k){
                if (v[i] + v[j] + v[k] == 2020){
                    fout << 1LL * v[i] * v[j] * v[k];
                    return 0;
                }
            }
        }
    }
    fin.close();
    fout.close();
}
