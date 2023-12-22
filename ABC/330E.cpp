#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N,Q; cin >> N >> Q;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    // mexは[0,N]になる
    vector<int> cnt(N+1, 0);
    for(int i = 0; i < N; i++){
        if(A[i] <= N) cnt[A[i]]++;
    }

    set<int> mexs;
    for(int i = 0; i <= N; i++){
        if(cnt[i] <= 0) mexs.insert(i);
    }

    while(Q--){
        int idx,x; cin >> idx >> x;
        idx--;
        
        // mexの追加
        if(A[idx] <= N){
            cnt[A[idx]]--;
            if(cnt[A[idx]] <= 0) mexs.insert(A[idx]);
        }
        
        // 変更
        A[idx] = x;

        // mexへの削除
        if(x <= N){
            cnt[x]++;
            if(mexs.count(x)) mexs.erase(x);
        }

        // set内の最小値がmex
        // printf("mex : "); for(auto v : mexs) cout << v << " "; cout << endl;
        // printf("cnt : "); for(auto v : cnt) cout << v << " "; cout << endl;
        // printf("A : "); for(auto v : A) cout << v << " "; cout << endl;

        cout << *mexs.begin() << endl;
    }
    return 0;
}