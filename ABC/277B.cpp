#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<string> S(N);
    for(int i = 0; i < N; i++){
        cin >> S[i];
    }

    bool f1=true, f2=true, f3=true;

    string s1 = "HDCS";
    string s2 = "A23456789TJQK";

    //1つめ
    for(int i = 0; i < N; i++){
        bool flag=false;

        for(int j = 0; j < 4; j++){
            if(S[i][0] == s1[j]){
                flag = true;
            }
        }
        if(!flag) f1=false;
    }

    //2つめ
    for(int i = 0; i < N; i++){
        bool flag=false;
        
        for(int j = 0; j < 13; j++){
            if(S[i][1] == s2[j]){
                flag = true;
            }
        }
        if(!flag) f2=false;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i==j){
                //何もしない

            }else{
                if(S[i]==S[j]){
                    f3 = false;
                }

            }
            
        }
    }

    if(f1 && f2 && f3) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}