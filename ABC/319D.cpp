#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> L(N);
    for(auto &_v : L) cin >> _v;
    for(auto &_v : L) _v++; //先頭に空白を追加

    ll ok = accumulate(L.begin(), L.end(), 0LL);
    ll ng = *max_element(L.begin(), L.end()) - 1;
    while(abs(ok-ng) >= 2){
        ll mid = (ok+ng)/2;

        bool flag = true;
        ll sum = 0;
        int line = 1;
        for(int i = 0; i < N; i++){
            sum += L[i];
            if(mid < sum){
                //超えてしまうなら改行
                line++;
                sum = L[i];
            }
        }

        if(line <= M){
            ok = mid;
        }else{
            ng = mid;
        }

        // printf("ok=%lld, ng=%lld\n",ok,ng);
    }

    cout << ok-1 << endl; //先頭の単語にも空白がついているので1文字小さい
    return 0;
}