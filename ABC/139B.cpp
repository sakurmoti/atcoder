#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int A,B;
    cin >> A >> B;

    int plug = 1;;
    int cnt=0;
    while(plug < B){
        plug--;
        plug+= A; //1個使ってA増やす
        cnt++;
    }

    cout << cnt << endl;
}