#include <bits/stdc++.h>

using namespace std;

ifstream fin("puzzle.in");
ofstream fout("puzzle.out");

set <pair <int, int> > fr;
int dx[] = {1, -1, 1, 0, 0, -1};
int dy[] = {0, 0, 1, 1, -1, -1};
int main(){
    string s;
    while (getline(fin, s)){
         int x = 0, y = 0, i = 0;
         while (i < s.size()){
            if (s[i] == 'e'){
                ++x;
                ++i;
            }
            else if (s[i] == 'w'){
                --x;
                ++i;
            }
            else if (s[i] == 'n'){
                if (s[i + 1] == 'e'){
                    ++y;
                    ++x;
                }
                else{
                    ++y;
                }
                i += 2;
            }
            else if (s[i] == 's'){
                if (s[i + 1] == 'e'){
                    --y;
                }
                else{
                    --y;
                    --x;
                }
                i += 2;
            }
         }
         if (fr.find({x, y}) != fr.end()){
            fr.erase(fr.find({x, y}));
         }
         else{
            fr.insert({x, y});
         }
    }
    for (int i = 1; i <= 100; ++i){
        map <pair <int, int>, int> cnt;
        for (auto it : fr){
            int x = it.first, y = it.second;
            for (int k = 0; k < 6; ++k){
                int xx = x + dx[k];
                int yy = y + dy[k];
                cnt[{xx, yy}]++;
            }
        }
        set <pair <int, int> > fr2;
        for (auto it : cnt){
            int x = it.first.first, y = it.first.second;
            if (fr.find({x, y}) != fr.end()){
                if (it.second == 0 || it.second > 2){

                }
                else{
                    fr2.insert({x, y});
                }
            }
            else{
                if (it.second == 2){
                    fr2.insert({x, y});
                }
            }
        }
        fr = fr2;
    }
    cout << fr.size();
    fin.close();
    fout.close();
    return 0;
}
