#include <bits/stdc++.h>

using namespace std;

ifstream fin("puzzle.in");
ofstream fout("puzzle.out");


char matrix[50][50][50], newMatrix[100][100][100];
int cnt[100][100][100];
int stiva[10];

struct triplet{
    int x, y, z;
};

void Back(int index, int x, int y, int z, vector <triplet> &vecini){
    if (index == 3){
        vecini.push_back({x + stiva[0], y + stiva[1], z + stiva[2]});
        return;
    }
    for (int i = -1; i <= 1; ++i){
        stiva[index] = i;
        Back(index + 1, x, y, z, vecini);
    }
}

int main(){
    memset(matrix, '.', sizeof matrix);
    string s;
    int row = 0, col = 0;
    while (getline(fin, s)){
        ++row;
        col = s.size();
        for (int i = 0; i < s.size(); ++i){
            matrix[row + 8][i + 8][8] = s[i];
        }
    }
    for (int cycle = 1; cycle <= 6; ++cycle){


        for (int i = 0; i <= 25; ++i){
            for (int j = 0; j <= 25; ++j){
                for (int k = 0; k <= 25; ++k){
                    if (matrix[i][j][k] == '#'){
                        for (int x = -1; x <= 1; ++x){
                            for (int y = -1; y <= 1; ++y){
                                for (int z = -1; z <= 1; ++z){
                                    if (x == 0 && y == 0 && z == 0){
                                        continue;
                                    }
                                    if (i + x < 0 || j + y < 0 || k + z < 0){
                                        continue;
                                    }
                                    cnt[i + x][j + y][k + z]++;
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
                    if (matrix[i][j][k] == '#'){
                        if (cnt[i][j][k] == 2 || cnt[i][j][k] == 3){
                            matrix[i][j][k] = '#';
                        }
                        else{
                            matrix[i][j][k] = '.';
                        }
                    }
                    else{
                        if (cnt[i][j][k] == 3){
                            matrix[i][j][k] = '#';
                        }
                        else{
                            matrix[i][j][k] = '.';
                        }
                    }
                }
            }
        }

        for (int i = 0; i <= 25; ++i){
            for (int j = 0; j <= 25; ++j){
                for (int k = 0; k <= 25; ++k){
                    cnt[i][j][k] = 0;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 25; ++i){
        for (int j = 0; j <= 25; ++j){
            for (int k = 0; k <= 25; ++k){
                if (matrix[i][j][k] == '#'){
                    ++ans;
                }
            }
        }
    }
    cout << ans;
    fin.close();
    fout.close();
}
