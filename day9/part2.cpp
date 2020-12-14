#include <bits/stdc++.h>

using namespace std;

ifstream fin("puzzle.in");
ofstream fout("puzzle.out");

int main(){
    vector <long long> v;
    long long x, nr;
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
            nr = v[i];
            break;
        }
    }
    for (int i = 0; i < v.size(); ++i){
        long long sum = v[i];
        int j = i + 1;
        while (j < v.size() && sum < nr){
            sum = sum + v[j];
            ++j;
        }
        if (sum == nr){
            long long minim = (1LL << 50), maxim = -(1LL << 50);
            for (int k = i; k < j; ++k){
                minim = min(minim, v[k]);
                maxim = max(maxim, v[k]);
            }
            fout << minim + maxim;
            return 0;
        }
    }
    fin.close();
    fout.close();
}
