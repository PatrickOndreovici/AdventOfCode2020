#include <bits/stdc++.h>

using namespace std;

ifstream fin("puzzle.in");
ofstream fout("puzzle.out");

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};


int main(){
    string s;
    int x = 0, y = 0, k = 0;
    while (fin >> s){
        int nr = 0;
        for (int i = 1; i < s.size(); ++i){
            nr = nr * 10 + s[i] - '0';
        }
        if (s[0] == 'N'){
            y += nr;
        }
        else if (s[0] == 'E'){
            x += nr;
        }
        else if (s[0] == 'S'){
            y -= nr;
        }
        else if (s[0] == 'W'){
            x -= nr;
        }
        else if (s[0] == 'F'){
            x += nr * dx[k];
            y += nr * dy[k];
        }
        else if (s[0] == 'R'){
            nr = nr / 90;
            k = (k + nr) % 4;
        }
        else if (s[0] == 'L'){
            nr = nr / 90;
            k = k - nr;
            while (k < 0) k += 4;
        }
    }
    fout << abs(x) + abs(y);
    fin.close();
    fout.close();
    return 0;
}
