#include <bits/stdc++.h>
using namespace std;

int main(){
    long long K;
    cin >> K;

    //Kが素数ならそのKを出力する
    //Kが合成数ならその素因数の最大値までNを増やす必要がある
    //まずはKを素因数分解
    map<long long,int> primeF;
    bool flag = true;
    long long temp = K;
    for(long long i = 2; i*i <= K; i++){
        if(temp%i == 0){
            flag = false;
            while(temp%i==0){
                primeF[i]++;
                temp/=i;
            }
        }
    }

    if(flag){
        //素数ならKを出力して終わり
        cout << K << endl;
    
    }else{
        for(auto itr = primeF.begin(); itr != primeF.end(); itr++) cout << itr->first << endl;

        //合成数なら素因数の最大値をとりあえず入れる。
        //んで残った最後の値が含まれるように調整する..?
        long long ans = prev(primeF.end(),1)->first;
        long long ls = temp;
        
        for(int i = 1; ; i++){
            if(ls*i < ans && !primeF.count(ls*i)){
                //最大値より小さく、素因数で使っていない
                //つまりans!の中に元から含まれている
                break;
            
            }else if(ans < ls*i){
                //ans!の中に含まれていなかったので
                //新しくans!を更新する必要がある
                ans = ls*i;
                break;
            }
        }
        
        cout << ans << endl;
    }


    return 0;
}