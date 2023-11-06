#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int N; cin >> N;
    

    for(int i = N; i <= 919; i++){
        int a = i/100;
        int b = (i%100)/10;
        int c = i%10;
    
        if(a*b == c){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}