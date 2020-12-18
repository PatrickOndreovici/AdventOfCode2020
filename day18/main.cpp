#include <bits/stdc++.h>

using namespace std;

ifstream fin("puzzle.in");
ofstream fout("puzzle.out");

char expresie[1000002];
int p = 0;

unsigned long long functia1();
unsigned long long functia2();
unsigned long long functia3();

int main(){
    unsigned long long ans = 0;
    string x;
    int cnt = 0;
    while (getline(fin, x)){
        int k = 0;
        ++cnt;
        for (int i = 0; i < x.size(); ++i){
            if (x[i] != ' '){
                expresie[k] = x[i];
                ++k;
            }
        }
        expresie[k] = '.';
        p = 0;
        ans = 1ULL * ans + 1ULL * functia1();
    }
    fout << ans << "\n";
    fin.close();
    fout.close();
    return 0;
}

unsigned long long functia1()
{
    unsigned long long r = functia2();
    while (expresie[p] == '*')
    {
        if (expresie[p] == '*'){
            ++p;
            r *= functia2();
        }
    }
    return r;
}


unsigned long long functia2()
{
    unsigned long long r = functia3();
    while (expresie[p] == '+')
    {
        if (expresie[p] == '+'){
            ++p;
            r += functia3();
        }
    }
    return r;
}


unsigned long long functia3()
{
    unsigned long long r = 0;
    if (expresie[p] == '(')
    {
        ++p;
        r = functia1();
        ++p;
    }
    else
    {
        while (expresie[p] >= '0' && expresie[p] <= '9')
        {
            r = r * 10 + expresie[p] - '0';
            ++p;
        }
    }
    return r;
}
