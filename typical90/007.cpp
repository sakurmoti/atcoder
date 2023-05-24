#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    sort(A.begin(), A.end());
    
    int B,Q;
    cin >> Q;
    for(int i = 0; i < Q; i++){
        cin >> B;

        //めぐる式二分探索でB以上のうち最小のAのindexを探す
        int ok = N-1;
        int ng = 0;
        int mid;
        while(ok - ng > 1){
            mid = (ok + ng)/2;

            /*真ん中がBよりまだ大きいならokを真ん中に寄せてもB以上のまま(真)ということ*/
            if( A.at(mid) - B > 0 ){
                ok = mid;
            }else{
                ng = mid;
            }

            //cout << abs(A.at(mid)-B) << endl;
        }

        //絶対値をとるのでokの場合の一つ前が答えの可能性もある
        if(ok != 0 && abs(A.at(ok)-B) > abs(A.at(ok-1)-B) ){
            cout << abs(A.at(ok-1)-B) << endl;
        }else{
            cout << abs(A.at(ok)-B) << endl;
        }

    }

    return 0;
}