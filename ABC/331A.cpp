#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()

int main(){
    int M,D; cin >> M >> D;
    int y,m,d; cin >> y >> m >> d;

    if(m==M && d==D){
        printf("%d %d %d\n",y+1,1,1);
    }else if(d==D){
        printf("%d %d %d\n", y,m+1,1);
    }else{
        printf("%d %d %d\n", y,m,d+1);
    }
    return 0;
}