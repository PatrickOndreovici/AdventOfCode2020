#include <bits/stdc++.h>

using namespace std;

ifstream fin("1-sir.in");

int n, m;
char matrix[1000][1000], newMatrix[1000][1000];
int dx[] = {1,-1,0,0,1,1,-1,-1};
int dy[] = {0,0,1,-1,1,-1,-1,1};

void Copy(){
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            newMatrix[i][j] = matrix[i][j];
        }
    }
}

void Copy2(){
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            matrix[i][j] = newMatrix[i][j];
        }
    }
}

bool Valid(int i, int j){
    return i >= 1 && j >= 1 && i <= n && j <= m && matrix[i][j] == '#';
}

int main(){
    string x;
    while (fin >> x){
        ++n;
        m = x.size();
        for (int j = 1; j <= m; ++j){
            matrix[n][j] = x[j - 1];
        }
    }
    bool pot = true;
    while (pot){
        pot = false;
        Copy();
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= m; ++j){
                int contor = 0;
                if (matrix[i][j] == 'L'){
                    for (int k = 0; k < 8; ++k){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (Valid(x, y)){
                            ++contor;
                        }
                    }
                    if (contor == 0){
                        newMatrix[i][j] = '#';
                        pot = true;
                    }
                }
                else if (matrix[i][j] == '#'){
                    for (int k = 0; k < 8; ++k){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (Valid(x, y)){
                            ++contor;
                        }
                    }
                    if (contor >= 4){
                        newMatrix[i][j] = 'L';
                        pot = true;
                    }
                }
            }
        }
        Copy2();
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (matrix[i][j] == '#'){
                ++ans;
            }
        }
    }
    cout << ans;
    return 0;
}
