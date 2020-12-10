#include <bits/stdc++.h>

using namespace std;

ifstream fin("1-sir.in");
ofstream fout("1-sir.out");
int v[10000], n, cnt[4], fr[10000];
long long dp[1000];

int main(){
    int x;
    while (fin >> x){
        v[++n] = x;
        fr[x] = 1;
    }
    sort(v + 1, v + n + 1);

    for (int i = 2; i <= n; ++i){
        cnt[v[i] - v[i - 1]]++;
    }
    cnt[v[1]]++;
    cnt[3]++;
    fr[v[n] + 3] = 1;
    dp[v[n] + 3] = 1;
    for (int i = v[n]; i >= 0; --i){
        if (fr[i + 1]){
            dp[i] = 1LL * dp[i] + dp[i + 1];
        }
        if (fr[i + 2]){
            dp[i] = 1LL * dp[i] + dp[i + 2];
        }
        if (fr[i + 3]){
            dp[i] = 1LL * dp[i] + dp[i + 3];
        }
    }
    fout << dp[0];
    return 0;
}
