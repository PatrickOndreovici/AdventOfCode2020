#include <bits/stdc++.h>

using namespace std;

ifstream fin("puzzle.in");
ofstream fout("puzzle.out");

deque <int> player1, player2;

bool solve(deque <int> &player1, deque <int> &player2, map <pair <deque <int>, deque <int> >, bool> &dp){
    while (player1.size() && player2.size()){
        if (dp[make_pair(player1, player2)]){
            return 0;
        }
        dp[make_pair(player1, player2)] = 1;
        int top1 = player1.front();
        player1.pop_front();
        int top2 = player2.front();
        player2.pop_front();
        if (top1 <= player1.size() && top2 <= player2.size()){
            deque <int> newPlayer1(player1.begin(), player1.begin() + top1);
            deque <int> newPlayer2(player2.begin(), player2.begin() + top2);
            map <pair <deque <int>, deque <int> >, bool> dp2;
            int winner = solve(newPlayer1, newPlayer2, dp2);
            if (winner == 0){
                player1.push_back(top1);
                player1.push_back(top2);
            }
            else{
                player2.push_back(top2);
                player2.push_back(top1);
            }
            if (player2.size() == 0){
                return 0;
            }
            if (player1.size() == 0){
                return 1;
            }
        }
        else{
            if (top1 >= top2){
                player1.push_back(top1);
                player1.push_back(top2);
            }
            else{
                player2.push_back(top2);
                player2.push_back(top1);
            }
            if (player2.size() == 0){
                return 0;
            }
            if (player1.size() == 0){
                return 1;
            }
        }
    }
}

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
    map <pair <deque <int>, deque <int> >, bool> dp;
    solve(player1, player2, dp);
    int ans = 0;
    for (int i = 1; i <= 50; ++i){
        ans += player1.back() * i;
        player1.pop_back();
    }
    cout << ans;
    fin.close();
    fout.close();
    return 0;
}
