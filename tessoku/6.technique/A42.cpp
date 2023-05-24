#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;

    vector<int> A(N),B(N);
    for (int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
    }

    //体力X,気力Yとして全探索する
    //参加者は多ければよく、X以上 X+K以下、Y以上Y+K以下の生徒全員を参加させればよい
    int ans = 0;
    for(int X = 0; X <= 100; X++){
        for(int Y = 0; Y <= 100; Y++){
            int count = 0;

            for(int i = 0; i < N; i++){
                if(X <= A[i] && A[i] <= X+K && Y <= B[i] && B[i] <= Y+K){
                    count++;
                }
            }

            if(ans < count) ans = count;
        }
    }
    
    cout << ans << endl;
    return 0;
}