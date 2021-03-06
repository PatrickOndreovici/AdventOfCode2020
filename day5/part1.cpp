#include <bits/stdc++.h>

using namespace std;

ifstream fin("puzzle.in");
ofstream fout("puzzle.out");

int main(){
    string x;
    int maxim = 0;
    while (fin >> x){
        int st = 0, dr = 127;
        for (int i = 0; i < 7; ++i){
            int mid = (st + dr) / 2;
            if (x[i] == 'F'){
                dr = mid;
            }
            else{
                st = mid + 1;
            }
    }
        int st2 = 0, dr2 = 7;
        for (int i = 7; i < 10; ++i){
            int mid = (st2 + dr2) / 2;
            if (x[i] == 'R'){
                st2 = mid + 1;
            }
            else{
                dr2 = mid;
            }
        }
        int id = (st * 8 + st2);
        maxim = max(maxim, id);
    }
    fout << maxim;
}
