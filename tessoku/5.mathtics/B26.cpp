#include <bits/stdc++.h>
using namespace std;

void Eratosthenes(vector<bool> &prime){
    //エラトステネスの篩
    for(int i = 2; i*i < prime.size(); i++){
        if(prime.at(i) == false){
            continue;
        
        }else{
            for(int j = 2; i*j < prime.size(); j++){
                prime.at(i*j) = false;
            }

        }
    }
}

int main(){
    int N;
    cin >> N;

    vector<bool> prime(N+1, true);
    //0,1は素数でない
    prime[0] = false;
    prime[1] = false;

    Eratosthenes(prime);

    for(int i = 0; i < prime.size(); i++){
        if(prime.at(i)){
            cout << i << endl;

        }
    }
    return 0;
}