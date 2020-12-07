#include <bits/stdc++.h>

using namespace std;

ifstream fin("1-sir.in");

int z = 0, ans = 0, viz[10000];
map <string, int> fr;
vector <int> G[10000];

void dfs(int nod){
    ++ans;
    viz[nod] = true;
    for (auto it : G[nod]){
        if (viz[it] == false){
            dfs(it);
        }
    }
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
        for (int i = 5; i < v.size(); i = i + 4){
            string aux2 = Concatenate(v[i], v[i + 1]);
            Add(aux2);
            if (aux2 == "shinygold"){
                start = fr[aux2];
            }
            G[fr[aux2]].push_back(fr[aux]);
        }
    }
    dfs(start);
    cout << ans - 1;
    return 0;
}
