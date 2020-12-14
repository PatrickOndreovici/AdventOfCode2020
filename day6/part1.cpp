#include <bits/stdc++.h>

using namespace std;

ifstream fin("puzzle.in");
ofstream fout("puzzle.out");

int main(){
    string x;
    int sum = 0;
    vector <int> fr(30);
    while (getline(fin, x)){
        if (x.size() == 0){
            for (char ch = 'a'; ch <= 'z'; ++ch){
                if (fr[ch - 'a']){
                    sum = sum + 1;
                }
                fr[ch - 'a'] = 0;
            }
        }
        else{
            for (int i = 0; i < x.size(); ++i){
                fr[x[i] - 'a']++;
            }
        }
    }
    for (char ch = 'a'; ch <= 'z'; ++ch){
        if (fr[ch - 'a']){
            sum = sum + 1;
        }
        fr[ch - 'a'] = 0;
    }
    fout << sum << "\n";
    fin.close();
    fout.close();
}
