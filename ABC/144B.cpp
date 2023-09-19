#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    ll a,b; cin >> a >> b;
    vector<ll> A(N); for(auto &_v : A) cin >> _v;

    //a <= bから操作を繰り返せば最大値は減っていく
    //単調性からにぶたんを考える

    //min(A) >= Cを達成できるか？
    int ok = 0; //1 <= Aiから可能
    int ng = *max_element(A.begin(), A.end()) + 1; //操作を行って最大値を超えることはない
    while(abs(ok-ng) >= 2){
        int mid = (ok+ng)/2;

        ll plus = 0, minus = 0;
        for(int i = 0; i < N; i++){
            //A[i] + k*a >= mid or A[i] - k*b >= mid
            //k >= (mid - A[i])/a or (A[i] - mid)/b >= k
            if(mid <= A[i]){
                minus += (A[i] - mid)/b;

            }else{
                plus += (mid - A[i])/a;
                if( (mid - A[i])%a != 0){
                    plus++; //切り捨てになってしまうので補正
                }
            }
        }

        //プラスの必要な回数が、マイナスの可能な回数より大きかったら不可能
        // printf("mid = %d, plus = %d, minus = %d\n", mid, plus, minus);
        if(plus <= minus){
            ok = mid;
        }else{
            ng = mid;
        }
    }

    cout << ok << endl;
    return 0;
}