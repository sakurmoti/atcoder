#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,K,Q;
    cin >> N >> K >> Q;
    
    ll ans = 0;
    vector<int> A(N+1, 0);
    priority_queue<int*, vector<int*>, greater<int*>> pq;
    for(int i = 1; i <= K; i++){
        pq.push(&A[i]);
    }

    //必要なのはA[x]はK番目以内だったのか、yになるとf(A)が更新されるか
    set<int> st;
    set<int> nowB; //現在のBの要素(idx)
    for(int i = 0; i < Q; i++){
        int x,y;
        cin >> x >> y;
        int* p = pq.top();
        int Bk = *p;

        if(Bk < y){
            //B[k]よりyの方が大きい
            if(nowB.count(x)){
                //A[x]がK以内だったなら
                ans = ans - A[x] + y;
                
            }else{
                //そうでなければB[k]を抜いて更新
                ans = ans - Bk + y;
            }
        
        }else{
            //B[k]よりyの方が小さい

        
        }

        A[x] = y;
        cout << "\t" << ans << endl;
    }


    return 0;
}