#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    vector<int> A(N);
    for(auto &_v : A) cin >> _v;

    // left[i] := 左から右に見ていった時、ピラミッド数列でiを中心としたときの最大サイズ
    vector<int> left(N, 1);
    for(int i = 1; i < N; i++){
        if(left[i-1]+1 <= A[i]){
            left[i] = left[i-1]+1;
        }else{
            left[i] = A[i];
        }
    }

    // right[i] := 右から左に見ていった時の最大サイズ
    vector<int> right(N, 1);
    for(int i = N-2; i >= 0; i--){
        if(right[i+1] + 1 <= A[i]){
            right[i] = right[i+1] + 1;
        }else{
            right[i] = A[i];
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        ans = max(ans, min(left[i], right[i]));
    }
    cout << ans << endl;
    return 0;
}