#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N,K;
    cin >> N >> K;

    //Kが奇数 -> XORっぽい？

    /*
    一般にK = kのとき

              A[x2] xor A[x3] xor ... xor A[xk] xor A[xk+1] = B[1]
    A[x1] xor       xor A[x3] xor ... xor A[xk] xor A[xk+1] = B[2]
    A[x1] xor A[x2] xor       xor ... xor A[xk] xor A[xk+1] = B[3]
    ...
    A[x1] xor A[x2] xor A[x3] xor ... xor A[xk]             = B[k+1]

    このようにk+1回繰り返す。
    例えばA[x1]を特定するにはB[2]~B[k+1]を選べばよい
    なぜならA[x1]はK個(奇数個)あり、他はどこかで一個ない->偶数個あるので
    A[x1] = B[2] xor B[3] xor ... xor B[k+1] が成り立つから

    あとは任意の値jに対して
    A[x1] xor A[x2] xor ... xor A[xk-1] xor A[j] = B[j]
    からA[j] = B[j] xor A[x1] xor ... xor A[xk-1]と言える
    */

    //1からK+1の特定(質問)
    vector<int> A(N+1), X(N+1), B(N+1);
    for(int i = 1; i <= N; i++){
        X[i] = i;
    }

    for(int i = 1; i <= K+1; i++){
        cout << "? ";
        for(int j = 1; j <= K+1; j++){
            if(i!=j){
                cout << X[j] << " ";
            }
        }
        cout << endl;

        cin >> B[i];
    }

    //1からK+1の特定(計算)
    for(int i = 1; i <= K+1; i++){
        int a = 0;
        for(int j = 1; j <= K+1; j++){
            if(i!=j){
                a ^= B[j];
            }
        }

        A[i] = a;
    }

    //A[1]からA[k-1]の排他的論理和
    int k_xor = 0;
    for(int i = 1; i <= K-1; i++){
        k_xor ^= A[i];
    }

    //K+2からNの特定(質問と計算)
    for(int i = K+2; i <= N; i++){
        cout << "? ";
        for(int j = 1; j <= K-1; j++){
            if(i!=j){
                cout << X[j] << " ";
            }
        }
        cout << X[i] << endl;

        cin >> B[i];
        A[i] = B[i] ^ k_xor;
    }
    
    //解答
    cout << "! ";
    for(int i = 1; i <= N; i++){
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}