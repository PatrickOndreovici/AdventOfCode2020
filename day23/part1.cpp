#include <bits/stdc++.h>

using namespace std;

ifstream fin("puzzle.in");
ofstream fout("puzzle.out");

int G[20];

void display(){
    int n = G[1];
    while (n != 1){
        fout << n;
        n = G[n];
    }
}

int main(){
    string x;
    fin >> x;
    for (int i = 0; i < x.size() - 1; ++i){
        G[x[i] - '0'] = x[i + 1] - '0';
    }
    G[x[x.size() - 1] - '0'] = x[0] - '0';
    int current = x[0] - '0';
    for (int moves = 1; moves <= 100; ++moves){
        int destination = current - 1;
        if (destination == 0){
            destination = x.size();
        }
        vector <int> fr(20), v;
        int n = current;
        for (int i = 1; i <= 3; ++i){
            n = G[n];
            fr[n] = 1;
            v.push_back(n);
        }
        G[current] = G[n];
        while (fr[destination]){
            --destination;
            if (destination == 0){
                destination = x.size();

            }
        }
        n = G[destination];
        G[destination] = v[0];
        G[v[0]] = v[1];
        G[v[1]] = v[2];
        G[v[2]] = n;
        current = G[current];
    }
    display();
    fin.close();
    fout.close();
    return 0;
}
