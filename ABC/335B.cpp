#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            for(int k = 0; k <= N; k++){
                if(i + j + k <= N){
                    printf("%d %d %d\n", i , j, k);
                }
            }
        }
    }
    return 0;
}