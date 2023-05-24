#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    if(N==1){
        cout << "Not Prime" << endl;
        return 0;
    }

    bool isPrime = true;
    //エラトステネス
    for(int i = 2; i*i <= N; i++){
        if(N%i == 0){
            isPrime = false;
            break;
        }
    }

    if(!isPrime){
        int grade = N%10; //下一桁
        int sum = 0; //各桁の和
    
        if(grade%2 == 0 || grade == 5){
            cout << "Not Prime" << endl;
            return 0;
        }

        while(N != 0){
            sum += (N%10);
            N/=10;
        }
        if(sum%3 == 0){
            cout << "Not Prime" << endl;
            return 0;
        }
    }

    cout << "Prime" << endl;

    
    return 0;
}