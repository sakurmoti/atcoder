#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    /*N=2では和に偶数ができるか不明*/
    if(N==2){
        int a,b;
        cin >> a >> b;

        if((a+b)%2 == 0){
            cout << a+b << endl;
        
        }else{
            cout << -1 << endl;
        }

        return 0;
    }

    //N>2では鳩ノ巣原理から必ず偶数を作ることができる
    vector<long long> even, odd;
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        
        if(a%2 == 0){
            even.push_back(a);
        
        }else{
            odd.push_back(a);

        }
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    int even_sum=-1, odd_sum=-1;
    
    /*2未満ではそもそも二要素選べない*/
    if(even.size() >= 2){
        even_sum = *(even.end()-1) + *(even.end()-2);
    }

    if(odd.size() >= 2){
        odd_sum = *(odd.end()-1) + *(odd.end()-2);
    }

    cout << max(even_sum, odd_sum) << endl;


    return 0;
}