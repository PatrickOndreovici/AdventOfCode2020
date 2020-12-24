#include <bits/stdc++.h>

using namespace std;

ifstream fin("puzzle.in");
ofstream fout("puzzle.out");

map <pair <int, int>, int> fr;

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
         fr[{x, y}]++;
    }
    int contor = 0;
    for (auto it : fr){
        if (it.second % 2 == 1){
            ++contor;
        }
    }
    cout << contor;
    fin.close();
    fout.close();
    return 0;
}
