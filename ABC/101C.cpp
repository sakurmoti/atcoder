#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,K; cin >> N >> K;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    // 全て1にするしかない
    // 順番はどうでもよく(できるように並び替えるとすればよい)、全ての区間を1回でも選択できればok
    // K-1個ずつ、N-1個の区間を埋めればよい
    cout << ceil((N-1.0)/(K-1)) << endl;
    return 0;
}