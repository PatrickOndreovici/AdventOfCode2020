#include <bits/stdc++.h>

using namespace std;

ifstream fin("mex2d.in");

long long sum = 0;
map <long long, long long> mp;

void Back(int index, vector <int> &v, long long add, long long nr){
    if (index == v.size()){
        mp[add] = nr;
        return;
    }
    Back(index + 1, v, add, nr);
    int x = v[index];
    Back(index + 1, v, (add | (1LL << x)), nr);
}

void solve(long long nr, string mask, long long a){
    long long add = 0, j = 0;
    vector <int> v;
    for (int i = mask.size() - 1; i >= 0; --i){
        if (mask[i] != 'X'){
            if (mask[i] == '1'){
                add |= (1LL << j);
            }
            int x = ((a >> j) & 1);
            if (x == 1)
                add |= (1LL << j);
        }
        else{
            v.push_back(j);
        }
        ++j;
    }
    Back(0, v, add, nr);
}

int main(){
    string mask, x;
    while (getline(fin, x)){
        bool masca = false;
        if (x[0] == 'm' && x[1] == 'a'){
            masca = true;
        }
        int i = 0;
        if (!masca){
            while (x[i] != '[') ++i;
            ++i;
            long long a = 0;
            while (x[i] != ']'){
                a = a * 10 + x[i] - '0';
                ++i;
            }
            while (x[i] != '=') ++i;
            i += 2;
            long long nr = 0;
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
