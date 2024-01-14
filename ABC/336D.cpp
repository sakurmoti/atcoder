#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    // サイズkのピラミッドを作れるとき、必ずサイズk-1のピラミッドも作れる。
    // ゆえに境界、単調性あり
    int ok = 1;
    int ng = N;
    while(abs(ok-ng) >= 2){
        int mid = (ok+ng)/2;
        // fprintf(stderr, "\tmid=%d\n", mid);

        // サイズmidのピラミッドを作れるか？
        bool isMake = false;

        vector<int> temp_mid;
        for(int i = 0; i < N; i++){
            if(mid <= A[i]){
                // サイズmidのピラミッドの最大値はmid, ゆえにmid以上のidxが候補
                
                if(mid <= i+1 && i <= N-mid){
                    // 左からmid以上離れていて、右からmid以上離れているか
                    temp_mid.push_back(i);
                }
            }
        }

        // midの候補はtemp_mid
        for(int i = 0; i < temp_mid.size(); i++){
            int center = temp_mid[i];
            // fprintf(stderr, "center = %d\n", center);

            bool flag = true;
            for(int j = 1; j < mid; j++){
                int up = center+j;
                int low = center-j;

                if(! (mid-j <= A[up] && mid-j <= A[low]) ){
                    flag = false;
                    break;
                }
            }

            if(flag){
                isMake = true;
                break;
            }
        }

        if(isMake){
            ok = mid;
        }else{
            ng = mid;
        }
    }

    cout << ok << endl;
    return 0;
}