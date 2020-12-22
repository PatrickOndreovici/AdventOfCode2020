#include <bits/stdc++.h>

using namespace std;

ifstream fin("puzzle.in");
ofstream fout("puzzle.out");

deque <int> player1, player2;

int main(){
    string player;
    while (getline(fin, player)){
        if (player.size() == 0){
            break;
        }
        if (player[0] >= '0' && player[0] <= '9'){
            int x = 0;
            for (int i = 0; i < player.size(); ++i){
                x = x * 10 + player[i] - '0';
            }
            player1.push_back(x);
        }
    }
    while (getline(fin, player)){
        if (player.size() == 0){
            break;
        }
        if (player[0] >= '0' && player[0] <= '9'){
            int x = 0;
            for (int i = 0; i < player.size(); ++i){
                x = x * 10 + player[i] - '0';
            }
            player2.push_back(x);
        }
    }
    while (player1.size() != 0 && player2.size() != 0){
        if (player1.front() >= player2.front()){
            player1.push_back(player1.front());
            player1.pop_front();
            player1.push_back(player2.front());
            player2.pop_front();
        }
        else{
            player2.push_back(player2.front());
            player2.pop_front();
            player2.push_back(player1.front());
            player1.pop_front();
        }
    }
    int ans = 0;
    for (int i = 1; i <= 50; ++i){
        if (player1.size()){
            ans = ans + player1.back() * i;
            player1.pop_back();
        }
        else{
            ans = ans + player2.back() * i;
            player2.pop_back();
        }
    }
    cout << ans;
    fin.close();
    fout.close();
    return 0;
}
