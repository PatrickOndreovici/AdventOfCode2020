#include <bits/stdc++.h>

using namespace std;

ifstream fin("puzzle.in");
ofstream fout("puzzle.out");

unordered_map <int, int> fr;
long long sum = 0, z, contor = 0;
vector <int> val;
int viz[200];
int c[1000][30];
vector <int> v;
unordered_map <int, int> idk[1000];
vector <int> G[100000];
void Add(string x){
    vector <int> aux;
    int i = 0;
    while (x[i] < '0' || x[i] > '9') ++i;
    int nr1 = 0;
    while (x[i] >= '0' && x[i] <= '9'){
        nr1 = nr1 * 10 + x[i] - '0';
        ++i;
    }
    ++i;
    int nr2 = 0;
    while (x[i] >= '0' && x[i] <= '9'){
        nr2 = nr2 * 10 + x[i] - '0';
        ++i;
    }
    ++z;
    for (int j = nr1; j <= nr2; ++j){
        fr[j] = 1;
        idk[z][j] = 1;
    }
    while (x[i] < '0' || x[i] > '9') ++i;
    nr1 = 0;
    while (x[i] >= '0' && x[i] <= '9'){
        nr1 = nr1 * 10 + x[i] - '0';
        ++i;
    }
    ++i;
    nr2 = 0;
    while (x[i] >= '0' && x[i] <= '9'){
        nr2 = nr2 * 10 + x[i] - '0';
        ++i;
    }
    for (int j = nr1; j <= nr2; ++j){
        fr[j] = 1;
        idk[z][j] = 1;
    }
}

void Check(string x){
    int nr = 0;
    int cnt = 0;
    bool gata = false;
    vector <int> aux;
    for (int i = 0; i < x.size(); ++i){
        if (x[i] >= '0' && x[i] <= '9'){
            nr = nr * 10 + x[i] - '0';
        }
        else{
            aux.push_back(nr);
            if (fr[nr] == 0){
                sum += nr;
                gata = true;
            }
            nr = 0;
        }
    }
    aux.push_back(nr);
    if (fr[nr] == 0){
        sum += nr;
        gata = true;
    }
    if (gata){
        return;
    }
    ++contor;
    for (int i = 0; i < aux.size(); ++i){
        for (int j = 1; j <= 20; ++j){
            if (idk[j][aux[i]]){
                c[i][j]++;
            }
        }
    }
}

void Back(int index, long long produs = 1LL){
    if (index == 21){
        cout << produs << "\n";
        return;
    }
    for (int i = 0; i < 20; ++i){
        if (c[i][index] == contor && viz[i] == 0){
            viz[i] = 1;
            if (index <= 6)
                Back(index + 1, 1LL * produs * val[i]);
            else{
                Back(index + 1, produs);
            }
            viz[i] = 0;
        }
    }
}

int main(){
    string x;
    string prev = "";
    bool adaug = true, pot = false;
    while (getline(fin, x)){
        if (prev == "your ticket:"){
            int nr = 0;
            for (int i = 0; i < x.size(); ++i){
                if (x[i] >= '0' && x[i] <= '9'){
                    nr = nr * 10 + x[i] - '0';
                }
                else{
                    val.push_back(nr);
                    nr = 0;
                }
    }
    val.push_back(nr);
        }
        if (x.size() == 0){
            adaug = false;
        }
        if (adaug == true){
            Add(x);
        }
        if (pot == true){
            Check(x);
        }
        if (x == "nearby tickets:"){
            pot = true;
        }
        prev = x;
    }
    int maxim = 0;
    Back(1);
    return 0;
}
