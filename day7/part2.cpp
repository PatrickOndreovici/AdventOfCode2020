#include <bits/stdc++.h>

using namespace std;

ifstream fin("puzzle.in");

int z = 0, ans = 0, viz[10000], dp[10000];
map <string, int> fr;
vector <pair <int, int> > G[10000];

int dfs(int nod){
    if (dp[nod] > 0) return dp[nod];
    int rasp = 1;
    for (auto it : G[nod]){
        int a = it.first;
        int b = it.second;
        rasp = rasp + b * dfs(a);
    }
    return dp[nod] = rasp;
}

bool Find(string a, string b){
    for (int i = 0; i < a.size(); ++i){
        if (a.size() - i < b.size()){
            break;
        }
        bool ok = true;
        for (int j = 0; j < b.size(); ++j){
            if (b[j] != a[i + j]){
                ok = false;
                break;
            }
        }
        if (ok){
            return true;
        }
    }
    return false;
}

string Concatenate(string a, string b){
    string aux = "";
    for (int i = 0; i < a.size(); ++i){
        aux += a[i];
    }
    for (int i = 0; i < b.size(); ++i){
        aux += b[i];
    }
    return aux;
}

int GetNumber(string a){
    int nr = 0;
    for (int i = 0; i < a.size(); ++i){
        nr = nr * 10 + a[i] - '0';
    }
    return nr;
}

void Add(string a){
    if (fr[a] == 0){
        ++z;
        fr[a] = z;
    }
}

int main(){
    string x;
    int start = 0;
    while (getline(fin, x)){
        string aux = "";
        vector <string> v;
        for (int i = 0; i < x.size(); ++i){
            if (x[i] == '.' || x[i] == ','){
                continue;
            }
            if (x[i] == ' '){
                v.push_back(aux);
                aux = "";
            }
            else{
                aux += x[i];
            }
        }
        v.push_back(aux);
        if (Find(x, "contain no")){
            continue;
        }
        aux = Concatenate(v[0], v[1]);
        Add(aux);
        if (aux == "shinygold"){
            start = fr[aux];
        }
        for (int i = 5; i < v.size(); i = i + 4){
            string aux2 = Concatenate(v[i], v[i + 1]);
            Add(aux2);
            int nr = GetNumber(v[i - 1]);
            G[fr[aux]].push_back({fr[aux2], nr});
        }
    }

    cout << dfs(start) - 1;
    return 0;
}
