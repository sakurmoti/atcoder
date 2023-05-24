#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

//エラトステネスの篩 O(N*log(logN)) ~= O(N)
vector<bool> Eratosthenes(int N){
    vector<bool> prime(N+1, true); //trueになっている添え字は素数

    for(int i = 0; i*i <= N; i++){
        if(i==0 || i==1) prime.at(i) = false;

        if(prime.at(i) == false){
            continue;
        
        }else{
            for(int j = 2; i*j < prime.size(); j++){
                prime.at(i*j) = false;
            }

        }
    }
    return prime;
}

#define MAXP 300010
vector<long long> sieve(){
    vector<long long> res;
    vector<int> mem(MAXP,0);
    for(int i=2;i<MAXP;i++){
        if(mem[i]){continue;}
        res.push_back(i);
        for(int j=i;j<MAXP;j+=i) {mem[j]=1;}
    }
    return res;
}

int main(){
    long long N;
    cin >> N;

    long long K = 0;
    for(long long i = 0; 12*i*i <= N; i++) K=i;
    vector<bool> p = Eratosthenes(K+1);
    
    vector<long long> prime = sieve();
    /*for(int i = 0; i <= K; i++){
        if(p.at(i)) prime.push_back(i);
    }*/
    int M = prime.size();

    cout << K << " " << M << endl;
    //for(int i = 0; i < prime.size(); i++) cout << prime[i] << endl;
    long long cnt = 0;
    for(int i = 0; i < M; i++){
        int k = M-1; //最大の素数を指すidx

        for(int j = i+1; (j < k)&&(j < M); j++){
            long long x = prime[i]*prime[i]*prime[j];

            while(j<k){    
                if(x > N){
                    k--;
                    continue;
                }
                x *= prime[k];

                if(x > N){
                    k--;
                    continue;
                }
                x *= prime[k];

                if(x > N){
                    k--;
                    continue;
                }
                break;
            }
            cnt += (k-j);
        }
    }
    cout << cnt << endl;
    return 0;
}