#include <bits/stdc++.h>
using namespace std;

int point(char a){
    if(a == 'W'){
        return 0;
    
    }else if(a == 'R'){
        return 1;
    
    }else{
        return 2;
    }
}

int main(){
    int N;
    cin >> N;

    char C;
    cin >> C;
    int target = point(C);

    int score = 0; //白を0点、赤を1点、青を2点とする
    for(int i = 0; i < N; i++){
        char a;
        cin >> a;

        score += point(a);
    }

    if(target == (score%3)) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}