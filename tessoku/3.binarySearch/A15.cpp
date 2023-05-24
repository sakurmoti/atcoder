#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> A(N), T(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    T = A;

    //座標圧縮
    //Aの重複を消しA[i]以下の数字の種類数を数えればよい
    sort(T.begin(), T.end());
    auto itr = unique(T.begin(), T.end());
    T.erase(itr, T.end());

    int idx = 1;
    vector<int> ans;
    for(int i = 0; i < N; i++){
        int ok = T.size()-1;
        int ng = -1;
        int mid = (ok+ng)/2;

        while(abs(ok-ng) > 1){
            if(T.at(mid) >= A.at(i)){
                ok = mid;

            }else{
                ng = mid;

            }

            mid = (ok+ng)/2;
        }

        //T[ok]以下がA[i]以下だが、0-idxを1-idxに直すため+1する
        ans.push_back(ok+1);
    }

    for(int i = 0; i < N; i++){
        cout << ans.at(i) << (i != N-1 ? " " : "\n");
    }
    return 0;
}