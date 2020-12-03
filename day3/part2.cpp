#include <bits/stdc++.h>

using namespace std;

ifstream fin("puzzle.in");
ofstream fout("puzzle.out");

char matrix[1000][105];
int dx[] = {1, 1, 1, 1, 2}, dy[] = {3, 1, 5, 7, 1};

int main(){
    string x;
    int n = 0, m = 0;
    while (fin >> x){
        m = x.size();
        for (int j = 0; j < m; ++j){
            matrix[n][j] = x[j];
        }
        ++n;
    }
    unsigned long long ans = 1;
    for (int k = 0; k < 5; ++k){
        int i = 0, j = 0;
        unsigned long long contor = 0;
        while (i < n){
            if (matrix[i][j] == '#') ++contor;
            i = i + dx[k];
            j = (j + dy[k]) % m;
        }
        ans = 1ULL * ans * contor;
    }
    fout << ans;
    fin.close();
    fout.close();
    return 0;
}
