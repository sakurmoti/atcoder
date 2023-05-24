#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,N;
    cin >> t >> N;

    //差分の小数部分
    double dp = t/100.0;

    long long A=0;
    long long price=0;
    double an = 0.0; //最初は0.0から始まるので小数部は0
    for(int i = 1; i <= N; i++){
        /*逆数の切り上げでrev_dp*dpは必ず1以上になる
        逆にrev_dp-1回は必ず連続で表れる
        ただし、小数部が0の時に限るのでその補正を1-anで行う*/
        int rev_dp = ceil( (1.00-an)/dp );
        //cout << (1.00-an)/dp << endl;
        
        /*anはA*(100+t)/100の小数部分
        A(1 + t/100)なので小数部分はAt/100 = A*dpの小数部分に一致
        最初に一円飛ばすのはA=rev_dpのとき、そこから新しく小数を求めなおす
        (ぴったり整数にならないかもしれないから)*/
        A += rev_dp;
        //cout << "A = " << A << ":: rev_dp = " << rev_dp << endl;
        //cout << "A*dp = " << A*dp << " floor() = " << floor(A*dp) << endl;

        an = A*dp - floor(A*dp); //A*dpの小数部分。次のdpを足す回数を求めるために更新
        //cout << "an = " << an << endl;

        //Aで求まる値の一つ前が飛ばされるので-1する
        price = floor( (A*(100.0+t)/100.0) ) - 1;
        //cout << price << endl;
    }

    cout << price << endl;

    
    return 0;
}