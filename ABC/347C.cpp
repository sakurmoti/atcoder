#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    ll N,A,B; cin >> N >> A >> B;
    vector<ll> D(N);
    for(auto &_v : D){
        cin >> _v;
        _v %= (A+B);
    }

    sort(ALL(D));
    for(int i = 0; i < N; i++){
        D.push_back(D[i] + A + B); // [1, 2(A+B)]の区間を見る
    }

    // for(auto &_v : D) cout << _v << " "; cout << endl;

    // A+B日の円を考えたとき、B日空くなら残りのA日で納められる = そこを全部休日になるような日が存在
    for(int i = 0; i < 2*N-1; i++){
        if(D[i+1] - D[i] > B){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}