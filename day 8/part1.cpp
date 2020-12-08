#include <bits/stdc++.h>

using namespace std;

ifstream fin("1-sir.in");

string v[10000];
int viz[10000];
int n = 0;

struct idk {
    int tip, nr;
}a[10000];

int solve(){
    int i = 1, acc = 0;
    memset(viz, 0, sizeof viz);
    while (i <= n){
        if (viz[i] == 1){
            return acc;
        }
        viz[i] = 1;
        if (a[i].tip == 0){
            ++i;
        }
        else if (a[i].tip == 1){
            acc = acc + a[i].nr;
            ++i;
        }
        else if (a[i].tip == 2){
            i += a[i].nr;
        }
    }
    return acc;
}

int main(){
    string x;
    while (getline(fin, x)){
        v[++n] = x;
        int j = 5, nr = 0;
        while (j < v[n].size()){
            nr = nr * 10 + v[n][j] - '0';
            ++j;
        }
        if (v[n][4] == '-') nr = nr * (-1);
        if (v[n][0] == 'n') a[n] = {0, nr};
        if (v[n][0] == 'a') a[n] = {1, nr};
        if (v[n][0] == 'j') a[n] = {2, nr};
    }
    cout << solve();
    return 0;
}
