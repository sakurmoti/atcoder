#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s;
    cin >> s;

    int Y = stoi(s.substr(0,4));
    int M = stoi(s.substr(5,2));
    int D = stoi(s.substr(8,2));
    // printf("%d/%d/%d",Y,M,D);
    
    bool ulu = false;
    if(Y%4==0){
        ulu=true;
        
        if(Y%100 == 0 && Y%400 != 0){
            ulu = false;
        }
    }

    vector<int> day(13,0);
    for(int i = 1; i <= 12; i++){
        if(i==2) day.at(i) = (ulu ? 29 : 28);
        else if(i==4 || i==6 || i==9 || i == 11) day.at(i) = 30;
        else day.at(i) = 31;
    }

    for(int i = M; i <= 12; i++){
        for(int j = 1; j <= day.at(i); j++){
            if(i==M && j < D) continue;

            if(Y % (i*j) == 0){
                printf("%d/%02d/%02d\n",Y,i,j);
                return 0;
            }
        }
    }
    printf("%d/%02d/%02d\n",Y+1,1,1);
    return 0;
}