#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> a(N);
    for(int i = 0; i < N; i++){
        cin >> a.at(i);
    }

    set<int> color;
    int any=0;
    for(int i = 0; i < N; i++){
        int rate = a.at(i)/400;

        if(a.at(i) < 3200){
            color.insert(rate);
        
        }else{
            any++;
        }

    }

    int m=0,M=0;
    for(int i = 0; i <= 8; i++){
        if(color.count(i)){
            m++;
        }
    }

    if(m==0 && any > 0){
        //みんな赤より上の場合一つの色にそろえるのが最小、全部別色にするのが最大
        m=1;
        M=any;
    
    }else{
        //赤以下がいる場合そこに色を揃えれば最小、全部別色にするのが最大
        M = m+any;
    }

    cout << m << " " << M << endl;
    return 0;
}