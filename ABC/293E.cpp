#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint;

int main(){
    int buf,M;
    long long X;
    cin >> buf >> X >> M;

    mint::set_mod(M);
    mint A = buf;

    set<int> num;
    mint sum = 0;
    for(long long i = 0; i < X-1; i++){
        mint x = A.pow(i);
        if(!num.count(x.val())){
            num.insert(x.val());
        
        }else{
            break;

        }

        sum += x.val();
    }


    
    return 0;
}