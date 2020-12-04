#include <bits/stdc++.h>

using namespace std;

ifstream fin("1-sir.in");
ofstream fout("1-sir.out");

unordered_map <string, int> fr;

int main(){
    string x;
    int contor = 0, ans = 0;
    char ch;
    bool ok = true;
    while (getline(fin, x)){
        if (x.size() == 0){
            if (contor == 8 && ok){
                ++ans;
            }
            else if (contor == 7 && fr["cid"] == 0 && ok){
                ++ans;
            }
            contor = 0;
            fr.clear();
            ok = true;
        }
        else{
            string aux = "";
            int i = 0;
            while (i < x.size()){
                aux += x[i];
                aux += x[i + 1];
                aux += x[i + 2];
                if (fr[aux] == 0) ++contor;
                fr[aux] = 1;
                i = i + 4;
                string data = "";
                while (x[i] != ' ' && i < x.size()){
                    data += x[i];
                    ++i;
                }
                if (aux == "byr"){
                    if (data.size() != 4) ok = false;
                    int nr = 0;
                    nr = nr * 10 + data[0] - '0';
                    nr = nr * 10 + data[1] - '0';
                    nr = nr * 10 + data[2] - '0';
                    nr = nr * 10 + data[3] - '0';
                    if (nr < 1920 || nr > 2002) ok = false;
                }
                if (aux == "iyr"){
                    if (data.size() != 4) ok = false;
                    int nr = 0;
                    nr = nr * 10 + data[0] - '0';
                    nr = nr * 10 + data[1] - '0';
                    nr = nr * 10 + data[2] - '0';
                    nr = nr * 10 + data[3] - '0';
                    if (nr < 2010 || nr > 2020) ok = false;
                }
                if (aux == "eyr"){
                    if (data.size() != 4) ok = false;
                    int nr = 0;
                    nr = nr * 10 + data[0] - '0';
                    nr = nr * 10 + data[1] - '0';
                    nr = nr * 10 + data[2] - '0';
                    nr = nr * 10 + data[3] - '0';
                    if (nr < 2020 || nr > 2030) ok = false;

                }
                if (aux == "hcl"){
                    if (data.size() != 7) ok = false;
                    if (data[0] != '#') ok = false;
                }
                if (aux == "ecl"){
                    if (data == "amb" || data == "blu" || data == "brn" || data == "gry" || data == "grn" || data == "hzl" || data == "oth"){

                    }
                    else{
                        ok = false;
                    }

                }
                if (aux == "pid"){
                    if (data.size() != 9) ok = false;
                    for (int j = 0; j < 9; ++j){
                        if (data[j] < '0' || data[j] > '9') ok = false;
                    }
                }
                if (aux == "hgt"){
                    int nr = 0;
                    string m = "";
                    for (int j = 0; j < data.size(); ++j){
                        if (data[j] >= '0' && data[j] <= '9'){
                            nr = nr * 10 + data[j] - '0';
                        }
                        else{
                            m += data[j];
                        }
                    }
                    if (m == "cm"){
                        if (nr < 150 || nr > 193) ok = false;
                    }
                    else{
                        if (nr < 59 || nr > 76) ok  = false;
                    }
                }

                ++i;
                aux = "";
            }
        }
    }
    if (contor == 8 && ok) ++ans;
    if (contor == 7 && fr["cid"] == 0 && ok) ++ans;
    fout << ans;
    return 0;
}
