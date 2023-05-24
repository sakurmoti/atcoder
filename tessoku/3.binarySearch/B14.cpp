#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    
    //カードの選び方を前半と後半で分ける
    //2^(N/2)の組合せを二つ作り、その二つの合計がKになるか確かめる
    vector<int> L,R;
    int temp;
    for(int i = 0; i < N/2; i++){
        cin >> temp;
        L.push_back(temp);
    }
    for(int i = (N/2); i < N; i++){
        cin >> temp;
        R.push_back(temp);
    }

    //半分全列挙
    //組合せを作るにはビット全探索する
    vector<long long> combL, combR;
    for(int i = 0; i < (1 << L.size()); i++){
        long long sum = 0;
        bitset<15> bitSearch(i);

        for(int j = 0; j < L.size(); j++){
            if(bitSearch.test(j)){
                //1が立っていたら加算
                sum += L.at(j);
            }
        }

        combL.push_back(sum);
    }
    
    for(int i = 0; i < (1 << R.size()); i++){
        long long sum = 0;
        bitset<15> bitSearch(i);

        for(int j = 0; j < R.size(); j++){
            if(bitSearch.test(j)){
                //1が立っていたら加算
                sum += R.at(j);
            }
        }

        combR.push_back(sum);
    }

    sort(combL.begin(), combL.end());
    sort(combR.begin(), combR.end());
    
    for(int i = 0; i < combL.size(); i++){
        int ok = combR.size()-1;
        int ng = -1;
        int mid = (ok+ng)/2;

        while(abs(ok-ng) > 1){
            if(combL.at(i) + combR.at(mid) >= K){
                ok = mid;

            }else{
                ng = mid;

            }

            mid = (ok+ng)/2;
        }

        if(combL.at(i) + combR.at(ok) == K){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}