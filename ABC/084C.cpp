#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    
    vector<int> C(N),S(N),F(N);
    for(int i = 1; i <= N-1; i++){
        cin >> C[i] >> S[i] >> F[i];
    }

    auto T = [&](int i, ll n){
        return S[i] + n*F[i];
    };

    for(int st = 1; st <= N; st++){
        int now = st;
        ll t = 0;
        while(now < N){
            // 駅iの発車時間Tnは Tn = Si + n*Fi
            // t <= Tnとなる最小のnを探す
            // 単調増加なので二分探索
            ll l = -1;
            ll r = 1e15;
            while(abs(l-r)>=2){
                ll mid = (l+r)/2;
                
                if(t <= T(now, mid)){
                    r = mid;
                }else{
                    l = mid;
                }
            }

            // printf("r = %lld\n", r);
            // printf("t = %d, next = %d, cost = %d\n",t, T(now,r), C[now]);

            t += abs(T(now,r)-t);
            t += C[now];
            now++;
        }

        cout << t << endl;
    }
    return 0;
}