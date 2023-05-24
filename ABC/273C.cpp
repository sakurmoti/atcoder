#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> A(N), B;
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    B = A;
    sort(B.begin(), B.end());
    auto itr = unique(B.begin(), B.end());
    B.erase(itr, B.end());
    
    /*for(int i = 0; i < B.size(); i++){
        cout << B[i] << " ";
    }
    cout << endl;*/
    
    /*Bには重複を除きソートされたAが入っている。二分探索でKを求めに行く*/
    vector<int> ans;
    for(int i = 0; i < N; i++){
        //okはA[i]より大きい、ngはA[i]以下のインデックス。[ng,ok)の区間で探索
        int ok = B.size();
        int ng = -1;
        int idx;
        while( (ok-ng) > 1){
            idx = (ok + ng) / 2;
            
            if(A.at(i) < B.at(idx)){
                ok = idx;
            
            }else{
                ng = idx;

            }

            //printf("idx=%d, ok=%d, ng=%d\n", idx,ok,ng);
        }
        
        int y = B.size()-ok;
        ans.push_back(y);
    }

    //今、ans[i]にはA[i]に関してAに含まれる整数のうちA[i]より大きい値の種類の個数が入っている。

    map<int,int> cnt;
    for(int i = 0; i < N; i++){
        if(cnt.count(ans.at(i))){
            cnt.at(ans.at(i))++;
        }else{
            cnt[ans.at(i)] = 1;
        }
        
        //cout << ans.at(i) << endl;
    }

    for(int i = 0; i < N; i++){
        cout << cnt[i] << endl;
    }
    return 0;
}