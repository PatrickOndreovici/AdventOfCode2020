#include <bits/stdc++.h>

using namespace std;

ifstream fin("puzzle.in");
ofstream fout("puzzle.out");

int z, fr[1000][1000], p[3000];
map <string, int> mp;
map <int, string> mpinv;
vector <int> G[1000];
vector <int> stanga, dreapta, total;


int viz[1000], l[1000], r[1000];
bool pairup(int nod){
    if (viz[nod]) return false;
    viz[nod] = true;
    for (auto it : G[nod]){
        if (r[it] == 0){
            l[nod] = it;
            r[it] = nod;
            return true;
        }
    }
    for (auto it : G[nod]){
        if (pairup(r[it])){
            l[nod] = it;
            r[it] = nod;
            return true;
        }
    }
    return false;
}

int main(){
    string line;
    while (getline(fin, line)){
        int i, n = line.size();
        string word = "";
        vector <int> cuvinte;
        for (i = 0; i < n; ++i){
            if (line[i] == '('){
                break;
            }
            if (isalpha(line[i])){
                word += line[i];
            }
            else{
                if (word.size() == 0){
                    continue;
                }
                if (mp[word] == 0){
                    ++z;
                    mp[word] = z;
                    mpinv[z] = word;
                    stanga.push_back(z);
                }
                cuvinte.push_back(mp[word]);
                total.push_back(mp[word]);
                word = "";
            }
        }
        word = "";
        for (int j = i + 10; j < n; ++j){
            if (isalpha(line[j])){
                word += line[j];
            }
            else{
                if (word.size() == 0){
                    continue;
                }
                if (mp[word] == 0){
                    ++z;
                    mp[word] = z;
                    mpinv[z] = word;
                    dreapta.push_back(z);
                }
                int val = mp[word];
                p[val]++;
                for (auto it : cuvinte){
                    fr[it][val]++;
                }
                word = "";
            }
        }
    }
    int ans = 0;
    vector <bool> bagat(1000);
    sort(dreapta.begin(), dreapta.end());
    stanga.clear();
    for (auto it : total){
        bool ok = true;
        for (auto it2 : dreapta){
            if (fr[it][it2] == p[it2]){
                ok = false;
                break;
            }
        }
        if (ok){
            ++ans;
        }
        else{
            if (bagat[it] == 0){
                stanga.push_back(it);
                int last = -1;
                for (auto it2 : dreapta){
                    if (it2 == last){
                        continue;
                    }
                    if (fr[it][it2] == p[it2]){
                        G[it].push_back(it2);
                    }
                    last = it2;
                }
            }
            bagat[it] = 1;
        }
    }
    bool ok = true;
    while (ok){
        ok = false;
        memset(viz, 0, sizeof viz);
        for (auto it : stanga)
            if (l[it] == 0)
                ok |= pairup(it);
    }
    map <string, string> aux;
    for (auto it : stanga){
        aux[mpinv[l[it]]] = mpinv[it];
    }
    for (auto it : aux){
        fout << it.second << ",";
    }
    fin.close();
    fout.close();
    return 0;
}
