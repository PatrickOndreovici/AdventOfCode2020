#include <bits/stdc++.h>

using namespace std;

ifstream fin("puzzle.in");
ofstream fout("puzzle.out");

int n;
long long last, current;
unordered_map <long long, int> fr;
int main(){
    fin >> n;
    for (int i = 1; i <= n; ++i){
        int x;
        fin >> x;
        if (i < n) fr[x] = i;
        else{
            last = x;
        }
    }
    for (long long i = n + 1; 1LL * i <= 1LL * 3 * 10000000; ++i){
        long long x = last;
        if (fr[x] == 0){
            current = 0;
        }
        else{
            current = i - fr[x] - 1;
        }
        fr[x] = i - 1;
        last = current;
    }
    cout << last;
    return 0;
}
