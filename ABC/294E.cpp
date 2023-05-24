#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    long long L,N,M;
    cin >> L >> N >> M;

    vector<long long> v1(N),l1(N);
    vector<long long> v2(M),l2(M);
    for(int i = 0; i < N; i++) cin >> v1[i] >> l1[i];
    for(int j = 0; j < M; j++) cin >> v2[j] >> l2[j];

    //lを書き換える
    for(int i = 1; i < N; i++) l1[i] += l1[i-1];
    for(int j = 1; j < M; j++) l2[j] += l2[j-1];
    
    //数字が変わるポイントをメモする
    vector<pair<long long, bool>> cp;
    for(int i = 0; i < N; i++) cp.push_back({l1[i], true});
    for(int j = 0; j < M; j++) cp.push_back({l2[j], false});
    sort(cp.begin(), cp.end());
    cp.erase(unique(cp.begin(),cp.end()), cp.end());

    long long ans=0;
    long long pre=0,now=0;
    int idx1=0, idx2=0;
    for(int i = 0; i < cp.size(); i++){
        now = cp.at(i).first; //変化するところまで見る
        bool flag = cp.at(i).second //どちらが変化するのか

        if(v1.at(idx1) == v2.at(idx2)){ //同じならカウント
            ans += (now-pre);
            
        }

        pre = now; //進める
    }

    cout << ans << endl;
    return 0;
}