#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N,K;
    cin >> N >> K;

    vector<int> A(N+1);
    vector<int> find(N+1,-1); //find[1]で1のidxがわかる
    for(int i = 1; i <= N; i++){
        cin >> A[i];
        find[A[i]] = i;
    }

    //1~N は1回ずつしか出てこない
    //つまり、最初の数字(L)をずらす度に基本的に順番は深くなっていく
    //L=1のときは1~NのN通り、L=2のときは最初の数字をのぞいたN-1通り、L=3の時はN-2通りずつ増えていく
    //ソートすると、L=1のとき1~A[1]のA[1]-1通り、L=2のときA[2]-1通り(A[1]<A[2])

    int L = (K/N)+1;

    vector<vector<int>> p;
    for(int L = 1; L <= N; L++){
        for(int R = L; R <= N; R++){
            if(L==R){
                p.push_back(A);
            
            }else{
                vector<int> B = A;
                reverse(B.begin()+L, B.begin()+R+1);
                p.push_back(B);
            }

            
        }
    }

    sort(p.begin(), p.end());

    for(int j = 0; j < p.size(); j++){
        cout << j+1 << ": "; 
        for(int i = 1; i <= N; i++){
            cout << p[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
} 