#include <bits/stdc++.h>

using namespace std;

ifstream fin("puzzle.in");
ofstream fout("puzzle.out");


char matrix[50][50][50][50];
int cnt[50][50][50][50];

int main(){
    memset(matrix, '.', sizeof matrix);
    string s;
    int row = 0, col = 0;
    while (getline(fin, s)){
        ++row;
        col = s.size();
        for (int i = 0; i < s.size(); ++i){
            matrix[row + 8][i + 8][8][8] = s[i];
        }
    }
    for (int cycle = 1; cycle <= 6; ++cycle){


        for (int i = 0; i <= 25; ++i){
            for (int j = 0; j <= 25; ++j){
                for (int k = 0; k <= 25; ++k){
                    for (int h = 0; h <= 25; ++h){
                            if (matrix[i][j][k][h] == '#'){
                                for (int x = -1; x <= 1; ++x){
                                    for (int y = -1; y <= 1; ++y){
                                        for (int z = -1; z <= 1; ++z){
                                            for (int w = -1; w <= 1; ++w){
                                                if (x == 0 && y == 0 && z == 0 && w == 0){
                                                    continue;
                                                }
                                                if (i + x < 0 || j + y < 0 || k + z < 0 || h + w < 0){
                                                    continue;
                                                }
                                                cnt[i + x][j + y][k + z][h + w]++;
                                            }
                                        }
                                    }
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i <= 25; ++i){
            for (int j = 0; j <= 25; ++j){
                for (int k = 0; k <= 25; ++k){
                    for (int h = 0; h <= 25; ++h){
                        if (matrix[i][j][k][h] == '#'){
                            if (cnt[i][j][k][h] == 2 || cnt[i][j][k][h] == 3){
                                matrix[i][j][k][h] = '#';
                            }
                            else{
                                matrix[i][j][k][h] = '.';
                            }
                        }
                        else{
                            if (cnt[i][j][k][h] == 3){
                                matrix[i][j][k][h] = '#';
                            }
                            else{
                                matrix[i][j][k][h] = '.';
                            }
                        }
                    }
                }
            }
        }

        memset(cnt, 0, sizeof cnt);
    }
    int ans = 0;
    for (int i = 0; i <= 25; ++i){
        for (int j = 0; j <= 25; ++j){
            for (int k = 0; k <= 25; ++k){
                for (int h = 0; h <= 25; ++h){
                        if (matrix[i][j][k][h] == '#'){
                            ++ans;
                    }
                }
            }
        }
    }
    cout << ans;
    fin.close();
    fout.close();
}
