#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

string S = "a0010011";
int judge(int x){
    if(0 <= x && x < S.size()){
        return (S[x] - '0');
    
    }else{
        exit(-1);
    }
}

int main(){
    int N;
    cin >> N;

    int one = N;
    int zero = 1;
    while(abs(one - zero) > 1){
        int mid = (one+zero)/2;

        cout << "? " << mid << endl;

        int ret;
        cin >> ret;
        //ret = judge(mid);

        if(ret == 0){
            zero = mid;
        }else{
            one = mid;
        }
    }

    cout << "! " << zero << endl;
    return 0;
}