#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;

    vector<int> p(N);
    for(int i = 0; i < N; i++) cin >> p.at(i);

    /*n個の目があるサイコロの期待値はすべて等確率であることから
    (1/n)*(1+2+...+n)なので(1/n)*(n(n+1)/2)とでき、約分して(n+1)/2 とわかる
    つまり、k個のサイコロを選んだ時の合計の期待値は((a1+a2+...ak)+k)/2 である
    ゆえにkは変わらないことから結局k個選んだ時の総和が最大となるところを選べばよい*/
    long long sum = 0;
    for(int i = 0; i < K; i++){
        //p[0]~p[k-1]までの総和
        sum += p.at(i);
    }

    long long maximum = sum;
    for(int i = K; i < N; i++){
        sum -= p.at(i-K); //左端を除いて
        sum += p.at(i); //右のものを加算

        if(maximum < sum) maximum = sum;
    }

    //合計の最大値を出したからあとは期待値を計算するのみ
    double expectation = (maximum+K)/2.0;
    printf("%lf\n", expectation);

    return 0;
}