#include <bits/stdc++.h>

using namespace std;

ifstream fin("puzzle.in");
ofstream fout("puzzle.out");

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};


int main(){
    string s;
    int x = 10, y = 1, k = 0;
    int x2 = 0, y2 = 0;
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
            x2 += nr * x;
            y2 += nr * y;
        }
        else if (s[0] == 'R'){
            nr = nr / 90;
            while (nr--){
                swap(x, y);
                y = -y;
            }
        }
        else if (s[0] == 'L'){
            nr = nr / 90;
            while (nr--){
                swap(x, y);
                x = -x;
            }
        }
    }
    fout << abs(x2) + abs(y2);
    fin.close();
    fout.close();
    return 0;
}
