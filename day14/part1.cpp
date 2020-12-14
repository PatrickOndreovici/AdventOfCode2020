#include <bits/stdc++.h>

using namespace std;

ifstream fin("mex2d.in");

long long sum = 0;
map <int, long long> mp;
void solve(long long nr, string mask, int a){
    long long add = 0, j = 0;
    for (int i = mask.size() - 1; i >= 0; --i){
        if (mask[i] != 'X'){
            if (mask[i] == '1'){
                add |= (1LL << j);
            }
        }
        else{
            int x = ((nr >> j) & 1);
            if (x == 1){
                add |= (1LL << j);
            }
        }
        ++j;
    }

    mp[a] = add;
}

int main(){
    string mask, x;
    while (getline(fin, x)){
        bool masca = false;
        if (x[0] == 'm' && x[1] == 'a'){
            masca = true;
        }
        int i = 0;
        long long nr = 0;
        if (!masca){
            while (x[i] != '[') ++i;
            ++i;
            int a = 0;
            while (x[i] != ']'){
                a = a * 10 + x[i++] - '0';
            }
            while (x[i] != '=') ++i;
            i += 2;
            while (i < x.size()){
                nr = nr * 10 + x[i++] - '0';
            }
            solve(nr, mask, a);
        }
        else{
            while (x[i] != '=') ++i;
            i += 2;
            mask = "";
            while (i < x.size()){
                mask += x[i++];
            }
        }
    }
    for (auto it : mp){
        sum = 1LL * sum + it.second;
    }
    cout << sum << "\n";
    return 0;
}
