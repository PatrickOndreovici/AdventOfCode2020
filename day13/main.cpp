#include <bits/stdc++.h>

using namespace std;

ifstream fin("puzzle.in");
ofstream fout ("puzzle.out");

long long Euclid(long long a, long long b, long long &x, long long &y){
    if (b == 0){
        x = 1;
        y = 0;
        return a;
    }
    else{
        long long x0, y0;
        long long d = Euclid(b, a % b, x0, y0);
        x = y0;
        y = x0 - 1LL * (a / b) * y0;
        return d;
    }
}

int main(){
    int k = 0;
    long long a[10], n[10], p[10], q[10];
    int v, nr = 0, cnt = 0;
    string s;
    fin >> v >> s;
    for (int i = 0; i < s.size(); ++i){
        if (s[i] >= '0' && s[i] <= '9'){
            nr = nr * 10 + s[i] - '0';
        }
        else if (s[i] == ',' && nr > 0){
            ++k;
            n[k] = nr;
            a[k] = (nr - cnt + nr * 100) % nr;
            nr = 0;
            ++cnt;
        }
        else if (s[i] == 'x'){
            ++cnt;
        }
    }
    ++k;
    n[k] = nr;
    a[k] = (nr - cnt + nr * 100) % nr;
    long long N = 1;
    for (int i = 1; i <= k; ++i){
        N = 1LL * N * n[i];
    }
    for (int i = 1; i <= k; ++i){
        p[i] = N / n[i];
        long long x, y;
        Euclid(p[i], n[i], x, y);
        if (x < 0) x = n[i] + x % n[i];
        q[i] = x;
    }
    long long ans = 0;
    for (int i = 1; i <= k; ++i){
        ans = (1LL * ans + 1LL * p[i] * a[i] % N * q[i] % N) % N;
    }
    cout << ans;
    fin.close();
    fout.close();
}
